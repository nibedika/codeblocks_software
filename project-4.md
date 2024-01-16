প্রজেক্ট - 8: রিয়েল-টাইম গ্রুপ চ্যাটিং / কমিউনিকেশন করার এপ্লিকেশন।
==========================================================================

সরাসরি প্রজেক্ট-এর কোড এ আসার পূর্বে চলো আমরা কোডটির কিছু বিষয় বস্তু সম্পর্কে ধারণা নিয়ে নেই, যাতে করে কোড ও-এর স্ট্রাকচারটা বুঝতে সুবিধা হবে।  
এই প্রজেক্ট-এর মাধ্যমে যেহেতু আমরা একটি গ্রুপ চ্যাটিং সিস্টেম তৈরী করবো তার মানে, এতে কমিউনিকেশন করার জন্য সারফেস প্ৰয়োজন হবে যেখান থেকে 
আমরা মেসেজ অন্য মেম্বারদের পাঠাতে পারবো। আবার একে অন্যকে কি মেসেজ পাঠালাম তা দেখার জন্যও আমাদের ঐ সারফেসে ডিসপ্লে সিস্টেম যুক্ত করতে হবে । 
আর এই কাজটি আমরা করতে পারি GUI ব্যবহার করে। GUI বলতে কি বোঝায় তা আমরা পূর্বের প্রজেক্ট এ জেনে এসেছি। এই প্রজেক্টে GUI হিসেবে আমরা WinAPI ব্যবহার করবো। 

এখন আসি, আমাদের এই কমিউনিকেশন সিস্টেমটির স্ট্রাকচার নিয়ে আলোচনায়। এই সিস্টেমটিতে প্রথমে আমরা socket ব্যবহার করে ক্লায়েন্ট / মেম্বার পারসনদের সার্ভার-এর সাথে যুক্ত করবো। 
ক্লায়েন্টগুলো সার্ভার-এর সাথে সফলভাবে যুক্ত হওয়ার বার্তা পেলে তারপর আমরা socket ব্যবহার করেই প্রত্যেক ক্লায়েন্টদের অন্য ক্লায়েন্টদের সাথে যুক্ত করবো। ক্লায়েন্টরা যখন নিজেদের মাঝে 
যুক্ত হয়ে গেলো তখন আমরা মেসেজ-এর আদান প্রদান-এর সিস্টেমকে  (feature) ক্লায়েন্টদের নিজেদের মাঝে তৈরী করবো। এভাবে ক্লায়েন্ট-এর সাথে ক্লায়েন্ট-এর কমিউনিকেশন সিস্টেম তৈরির 
পদ্ধতিকে peer কমিউনিটেশন বলা হয়ে থাকে। এখন আমরা এই কাজটি ধাপে ধাপে কোড-এর মাধ্যমে প্রকাশ করি চলো।  

এই অংশে রিয়েল-টাইম গ্রুপ চ্যাটিং / কমিউনিকেশন করার যে প্রোগ্রামটি আমরা করবো সেটা উইন্ডোস অপারেটিং-এর মাঝে অপারেট করার জন্য তৈরী করবো। আমাদের প্রজেক্টটিতে ২টি প্রোগ্রাম 
ফাইল থাকবে। তাই চলো শুরুতেই আমরা আমাদের কম্পিউটারের সি প্রোগ্রামের ডিরেক্টরি মানে, যেখানে আমরা এতদিন পূর্বের কোডগুলো সেভ করেছি সেখানে Project-4 লিখে একটি ফোল্ডার 
তৈরী করি এবং সেই ফোল্ডার-এর মাঝে server.c এবং client.c নামে ২টি সি প্রোগ্রামিং ফাইল তৈরী করি। ফাইল তৈরী হয়ে গেলে আমার নিচে দেখানো কোডগুলো নিজ নিজ সি ফাইলে তুলে নিয়ে 
সেভ করবো। প্রোগ্রামটিগুলোতে কোন অংশে কি করা হয়েছে তা সাথে কমেন্ট করে বোঝিয়ে দেওয়া হয়েছে তোমাদের সুবিধার জন্য। কোডগুলো আমাদের নির্দিষ্ট ফাইলে সেভ করে নেওয়া পর আমার 
এই প্রজেক্টটি বিল্ড এবং রান করার পদ্ধতিও জানবো।  



server.c ফাইল কোড:
----------------------
// socket সম্পর্কিত কাজের জন্য হেডার ফাইল
#include<winsock2.h>

// Windows API উইন্ডো নিয়ে কাজ করার জন্য হেডার ফাইল
#include<windows.h>

// ইনপুট আউটপুট-এর কাজ করার জন্য হেডার ফাইল
#include<stdio.h>

// যোগাযোগ পদ্ধতির পোর্ট ডিফাইন করা
#define PORT 12345

/* সর্বাধিক কত জন ক্লায়েন্ট অর্থাৎ মানুষ নিজেদের মাঝে কমিউনিকেশন
করতে পারবে তা ডিফাইন করা। এখানে আমরা আমাদের নিজেদের ইচ্ছে
মতো সংখ্যা নিতে পারবো।    */
#define MAX_CLIENTS 10

/* Winsock লাইব্রেরিতে SOCKET হলো একটি ডাটা টাইপ যা দ্বারা
socket ডিফাইন করা হয়। socket দ্বারাই client side এর
সাথে Client side অর্থাৎ peer-to-peer এবং client side
এর সাথে  server side-এর যোগাযোগ-এর মাধ্যম তৈরী করা হয় */
SOCKET client_sockets[MAX_CLIENTS];

int num_clients = 0;

/* প্রোগ্রামে একটি কাজের পাশাপাশি অন্য কাজগুলো স্বাধীনভাবে করার সিস্টেম
হলো Thread procedure আর এখানে WINAPI-এর Thread
procedure হিসেবে ReceiveThread ফাংশন কাজ করেছে */
DWORD WINAPI HandleClientThread(LPVOID lpParam) {

    // ক্লায়েন্ট সাইড-এর জন্য socket ইনিশিয়ালাইজ করা
    int clientIndex = (int)(intptr_t)lpParam;
    SOCKET client_socket = client_sockets[clientIndex];

    /* প্রাপ্ত ডাটা স্টোর করার জন্য প্রাথমিক ভাবে 0 দ্বারা ইনিশিয়ালাইজ করে
            একটি ক্যারেক্টার array নেওয়া */
    char buffer[1024];

    // ক্রমাগত ডাটা পাওয়ার জন্য লুপ এটি
    while (1) {

        // ক্লায়েন্ট socket থেকে buffer এ ডাটা রিসিভ করার জন্য ফাংশন
        int bytesRead = recv(client_socket, buffer, sizeof(buffer) - 1, 0);

        // ডাটা সফলভাবে রিসিভ হয়েছে কিনা তা পরীক্ষা করা
        if (bytesRead > 0) {

            //'\0' ভ্যালু রিসিভ হলে ডাটা রিসিভ ব্রেক করে দেওয়া
            buffer[bytesRead] = '\0';

            /* কোনো ক্লায়েন্ট-এর থেকে প্রাপ্ত মেসেজ কে সকল
                                ক্লায়েন্ট-এর কাছে পাঠানো  */
            for (int i = 0; i < num_clients; ++i) {
                if (i != clientIndex) {
                    send(client_sockets[i], buffer, bytesRead, 0);
                }
            }
        } else if (bytesRead == 0) {
            // ক্লায়েন্ট ডিসকানেক্ট হয়ে গেলে লুপ ব্রেক করে দেওয়া
            printf("Client %d disconnected\n", clientIndex);
            break;
        } else {
            // ক্লায়েন্ট সাইট থেকে ডাটা রিসিভের এরর প্রিন্ট করা
            printf("Error in receiving data from client %d: %d\n", clientIndex, WSAGetLastError());
            break;
        }

        /* সিস্টেম ওয়েটিং পিরিয়ড দূর করতে 100 milliseconds
                     -এর স্লিপিং পিরিয়ড ডিফাইন করা হয়েছে  */
        Sleep(100);
    }

    // ক্লায়েন্ট সকেট বন্ধ করা
    closesocket(client_socket);
    return 0;
}


int main() {

    /* WSADATA ডাটা টাইপের wsa এখানে,
    Windows Sockets ব্যবহারের তথ্য স্টোর করে */
    WSADATA wsa;

    // সার্ভার সাইড-এর জন্য socket ইনিশিয়ালাইজ করা
    SOCKET server_socket;

    // সার্ভার এবং ক্লায়েন্ট লোকেশন সম্পর্কিত তথ্য স্টোর করা
    struct sockaddr_in server, client;

    int c;

    // Winsock লাইব্রেরি ইনিশিয়ালাইজ করা এবং ফেইল হলে এরর প্রিন্ট
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed. Error Code: %d", WSAGetLastError());
        return 1;
    }

    // সার্ভার সাইড socket তৈরী এবং না হলে এরর মেসেজ প্রিন্ট
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket: %d", WSAGetLastError());
        return 1;
    }

    /* server socker-এর address family
            হিসেবে IPv4 সেট করা */
    server.sin_family = AF_INET;

    // কোনো ব্যবহারযোগ্য নেটওয়ার্ক ইন্টারফেসে সার্ভার IP সেট করা
    server.sin_addr.s_addr = INADDR_ANY;

    // সার্ভার socket এ পোর্ট নম্বর সেট করা
    server.sin_port = htons(PORT);

    /* নির্দিষ্ট আইপি এড্রেস এবং পোর্ট-এর সাথে সকেটকে সংযুক্ত করা
            এবং না হলে এরর মেসেজ প্রিন্ট করা  */
    if (bind(server_socket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        printf("Bind failed with error code: %d", WSAGetLastError());
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }
    printf("Bind done\n");

    // ইনকামিং সংযোগ আসছে কিনা চেক করা
    listen(server_socket, 3);

    // ইনকামিং সংযোগ-এর জন্য অপেক্ষা করা
    printf("Waiting for incoming connections...\n");

    while (1) {

        // ইনকামিং সংযোগ গ্রহণ করা
        c = sizeof(struct sockaddr_in);
        SOCKET client_socket = accept(server_socket, (struct sockaddr*)&client, &c);

        // ইনকামিং সংযোগ অচল কিনা চেক করা
        if (client_socket == INVALID_SOCKET) {

            // সংযোগ ফেইল হলে এরর মেসেজ প্রিন্ট করা
            printf("Accept failed with error code: %d", WSAGetLastError());

            // সার্ভার সকেট বন্ধ করা
            closesocket(server_socket);

            // Winsock সম্পর্কিত তথ্য মুছে ফেলা
            WSACleanup();

            return 1;
        }

        /* ক্লায়েন্ট সংখ্যা সর্বাধিক সংখ্যা অতিক্রম করেছে কিনা চেক করা  */
        if (num_clients < MAX_CLIENTS) {

            // নতুন ক্লায়েন্ট-এর জন্য সকেট ডিফাইন করা
            client_sockets[num_clients] = client_socket;

            /* ক্রমাগত মেসেজ পাওয়ার জন্য `CreateThread`
                                কল করে নতুন থ্রেড শুরু করা */
            HANDLE clientThread = CreateThread(NULL, 0, HandleClientThread, (LPVOID)(intptr_t)num_clients, 0, NULL);

            // নতুন ক্লায়েন্ট কানেকশন গ্রহণ করা
            printf("Connection accepted from client %d\n", num_clients);

            // Increment the number of clients
            ++num_clients;
        } else {
            /* সর্বাধিক সংখ্যক ক্লায়েন্ট-এর চেয়ে বাড়তি ক্লায়েন্ট
                               -এর জন্য কানেকশন ব্রেক করে দেওয়া  */
            printf("Connection rejected. Maximum number of clients reached.\n");
            closesocket(client_socket);
        }
    }

    // সার্ভার সকেট বন্ধ করা
    closesocket(server_socket);

    // Winsock সম্পর্কিত তথ্য মুছে ফেলা
    WSACleanup();

    return 0;
}



client.c ফাইল কোড:
----------------------
// socket সম্পর্কিত কাজের জন্য হেডার ফাইল
#include<winsock2.h>

// Windows API উইন্ডো নিয়ে কাজ করার জন্য হেডার ফাইল
#include<windows.h>

// ইনপুট আউটপুট-এর কাজ করার জন্য হেডার ফাইল
#include<stdio.h>

// Graphical User Interface(GUI)-এর আউটপুট  বক্সকে ডিফাইন করা
#define ID_OUTPUT_BOX 101

// Graphical User Interface(GUI)-এর ইনপুট  বক্সকে ডিফাইন করা
#define ID_INPUT_BOX 102

// Graphical User Interface(GUI)-এর সেন্ড বাটনকে  ডিফাইন করা
#define ID_SEND_BUTTON 103

// যোগাযোগ পদ্ধতির পোর্ট ডিফাইন করা
#define PORT 12345

// সার্ভার IP ডিফাইন করা
#define SERVER_IP "127.0.0.1"

/* সর্বাধিক কত জন ক্লায়েন্ট অর্থাৎ মানুষ নিজেদের মাঝে কমিউনিকেশন
করতে পারবে তা ডিফাইন করা। এখানে আমরা আমাদের নিজেদের ইচ্ছে
মতো সংখ্যা নিতে পারবো।    */
#define MAX_CLIENTS 10

/* Windows API-এর উইন্ডো হ্যান্ডেল করার জন্য HWND হলো একটি
ডাটা টাইপ এবং এখানে এই ডাটা টাইপ দিয়ে outputBox, inputBox
এবং editBox কে ডিফাইন করা হয়েছে এখানে  */
HWND outputBox;
HWND inputBox;
HWND sendButton;

/* Winsock লাইব্রেরিতে SOCKET হলো একটি ডাটা টাইপ যা দ্বারা socket
ডিফাইন করা হয়। socket দ্বারাই client side থেকে server side
এর সাথে যোগাযোগ-এর মাধ্যম তৈরী করা হয় */
SOCKET client_socket;

// ক্লায়েন্ট উইন্ডো তৈরী-এর সময় ক্লায়েন্ট নাম সেট করার জন্য ভ্যারিয়েবল
const char* clientName;

// HWND ডাটা টাইপের hwnd ভ্যারিয়েবল দ্বারা মেইন উইন্ডো হ্যান্ডেল বোঝায়
HWND hwnd;

// আউটপুট বক্সে এক্সেস ম্যানেজ করার জন্য হ্যান্ডেল হলো hOutputMutex
HANDLE hOutputMutex;

// ক্লায়েন্ট অনুযায়ী ডাটা স্টোর করার জন্য স্ট্রাকচার
typedef struct {
    HWND hwnd;
    HWND outputBox;
    const char* clientName;
} ClientData;

ClientData clientData[MAX_CLIENTS];
int numClients = 0;

// ক্লায়েন্ট উইন্ডো তৈরী-এর সময় ক্লায়েন্ট নাম সেট করার জন্য ফাংশন
void SetClientName(const char* name) {
    clientName = name;
}

// উইন্ডোতে মেসেজ ডিসপ্লে করা অর্থাৎ দেখানোর জন্য ফাংশন
void AppendMessageToWindow(HWND window, const char* message) {

    /* hOutputMutex অবজেক্ট-এর সিগন্যাল স্টেট এ
           আসার জন্য অপেক্ষা করা */
    WaitForSingleObject(hOutputMutex, INFINITE);

    // // প্রাপ্ত মেসেজ outputBox এ সেট করা
    SendMessage(window, EM_SETSEL, -1, -1);

    // পুনরায় প্রাপ্ত মেসেজ outputBox এ প্রবেশ করানো
    SendMessage(window, EM_REPLACESEL, 0, (LPARAM)message);

    // নতুন প্রাপ্ত মেসেজে-এর শেষ পর্যন্ত outputBox নিয়ে আসা
    SendMessage(window, EM_SCROLLCARET, 0, 0);

    // hOutputMutex অবজেক্ট-এর কাজ শেষ করা
    ReleaseMutex(hOutputMutex);
}

// অন্য ক্লায়েন্টকে মেসেজ সেন্ড করার জন্য ফাংশন
void SendMessageToClient(const char* clientName, const char* message) {
    char buffer[1024];

    // মেসেজ ফরমেট করা
    sprintf(buffer, "%s: %s\n", clientName, message);

    // মেসেজ সেন্ড করা
    send(client_socket, buffer, strlen(buffer), 0);

    // মেসেজ উইন্ডোতে দেখানো
    AppendMessageToWindow(outputBox, buffer);
}

/* প্রোগ্রামে একটি কাজের পাশাপাশি অন্য কাজগুলো স্বাধীনভাবে করার সিস্টেম
হলো Thread procedure আর এখানে WINAPI-এর Thread
procedure হিসেবে ReceiveThread ফাংশন কাজ করেছে */
DWORD WINAPI ReceiveThread(LPVOID lpParam) {

    /* প্রাপ্ত ডাটা স্টোর করার জন্য প্রাথমিক ভাবে 0 দ্বারা ইনিশিয়ালাইজ করে
            একটি ক্যারেক্টার array নেওয়া */
    char buffer[1024];

    // ক্রমাগত ডাটা পাওয়ার জন্য লুপ এটি
    while (1) {

        // ক্লায়েন্ট socket থেকে buffer এ ডাটা রিসিভ করার জন্য ফাংশন
        int bytesRead = recv(client_socket, buffer, sizeof(buffer) - 1, 0);

        // ডাটা সফলভাবে রিসিভ হয়েছে কিনা তা পরীক্ষা করা
        if (bytesRead > 0) {

            //'\0' ভ্যালু রিসিভ হলে ডাটা রিসিভ ব্রেক করে দেওয়া
            buffer[bytesRead] = '\0';

            // প্রাপ্ত ডাটা থেকে ক্লায়েন্ট নাম এবং মেসেজকে আলাদা করা
            char* delimiter = strchr(buffer, ':');
            if (delimiter != NULL) {
                *delimiter = '\0';

                // ক্লায়েন্ট নাম স্টোর করা
                char* clientName = buffer;

                // মেসেজ স্টোর করা
                char* message = delimiter + 1;

                //  মেসেজ ফরমেট করা
                char formattedMessage[1024];
                sprintf(formattedMessage, "%s: %s\n", clientName, message);

                // নিজের উইন্ডোতে মেসেজ দেখানো
                AppendMessageToWindow(outputBox, formattedMessage);
            }

        } else if (bytesRead == 0) {
            // ক্লায়েন্ট ডিসকানেক্ট হয়ে গেলে লুপ ব্রেক করে দেওয়া
            MessageBox(NULL, "Connection closed by the server.", "Info", MB_ICONINFORMATION);
            break;
        } else {
            // ক্লায়েন্ট সাইট থেকে ডাটা রিসিভের এরর প্রিন্ট করা
            MessageBox(NULL, "Error in receiving data.", "Error", MB_ICONERROR);
            break;
        }

        /* সিস্টেম ওয়েটিং পিরিয়ড দূর করতে 100 milliseconds
                     -এর স্লিপিং পিরিয়ড ডিফাইন করা হয়েছে  */
        Sleep(100);
    }

    return 0;
}


/* এখানে `WindowProcedure` ফাংশন ডিক্লেয়ার করা হয়েছে।
উইন্ডোতে সেন্ড করা মেসেজেকে অপারেটিং সিস্টেম ডাটা কল করার
জন্য কল-ব্যাক ফাংশন এটি। আর callback ফাংশন বলতে ঐ সকল
ফাংশনকে বোঝায় যাদের অন্য ফাংশনে আর্গুমেন্ট আকারে পাঠানো হয়  */
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {

    // মেসেজে টাইপের উপর ভিত্তি করে switch স্ট্যাটমেন্ট দ্বারা চেক করা
    switch (message) {

        // প্রাপ্ত মেসেজটি CREATE মেসেজ কিনা চেক করা
        case WM_CREATE: {

            // ক্লায়েন্ট অনুযায়ী ক্লায়েন্ট-এর প্রাথমিক তথ্য সেট করা
            clientData[numClients].hwnd = hwnd;
            clientData[numClients].outputBox = outputBox;
            clientData[numClients].clientName = "Client";
            numClients++;
            break;
        }

        // প্রাপ্ত মেসেজটি COMMAND মেসেজ কিনা চেক করা
        case WM_COMMAND: {
            switch (LOWORD(wParam)) {

                /* কম্যান্ডটি সেন্ড মেসেজ হয়ে থাকলে
                                           মেসেজ সেন্ড করা */
                case ID_SEND_BUTTON: {

                    // ইনপুট বক্স থেকে মেসেজ গ্রহণ করা
                    char buffer[1024];
                    GetWindowText(inputBox, buffer, sizeof(buffer));

                    // কানেক্টেড ক্লায়েন্টকে মেসেজ সেন্ড করা
                    SendMessageToClient(clientName, buffer);

                    // মেসেজ ইনপুট বক্স ক্লিয়ার করা
                    SetWindowText(inputBox, "");

                    break;
                }
            }
            break;
        }

        // উইন্ডোটি ক্লোস করা হয়ে গেছে কিনা চেক করা
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }

        //ডিফল্ট মেসেজ হ্যান্ডেলিং
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}


// একটি উইন্ডো-এর GUI কন্ট্রোল করার জন্য এই ফাংশনটি তৈরী করা হয়েছে
void CreateControls(HWND hwnd) {

    /* উইন্ডোতে ইনপুট বক্স তৈরী করার ফাংশন এটি যেখানে `EDIT` হলো
    edit কন্ট্রোল, `WS_CHILD | WS_VISIBLE | WS_BORDER |
    ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY` হলো
            উইন্ডোটির ডিজাইন অপসন, `10, 10, 400, 200` দ্বারা উইন্ডোটির অবস্থান এবং
            সাইজ ডিফাইন হয়েছে, `hwnd` দ্বারা প্যারেন্ট উইন্ডো কন্ট্রোল,
    `ID_OUTPUT_BOX` দ্বারা উইন্ডোতে আউটপুট কন্ট্রোল,
    `GetModuleHandle()` হলো মডিউল কল হ্যান্ডলার  */
    outputBox = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY,
                               10, 10, 400, 200, hwnd, (HMENU)ID_OUTPUT_BOX, GetModuleHandle(NULL), NULL);

    /* আউটপুট বক্স-এর মতোই এখানে ইনপুট বক্স তৈরী করা হয়েছে উইন্ডোতে */
    inputBox = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
                               10, 220, 300, 20, hwnd, (HMENU)ID_INPUT_BOX, GetModuleHandle(NULL), NULL);

    /* এখানে সেন্ড বাটন তৈরী করা হয়েছে উইন্ডোতে  */
    sendButton = CreateWindow("BUTTON", "Send", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
                              320, 220, 90, 20, hwnd, (HMENU)ID_SEND_BUTTON, GetModuleHandle(NULL), NULL);
}



int main() {

    /* WSADATA ডাটা টাইপের wsa এখানে,
    Windows Sockets ব্যবহারের তথ্য স্টোর করে */
    WSADATA wsa;

    // সার্ভার  লোকেশন সম্পর্কিত তথ্য স্টোর করা
    struct sockaddr_in server;

    // Winsock লাইব্রেরি ইনিশিয়ালাইজ করা এবং ফেইল হলে এরর প্রিন্ট
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        MessageBox(NULL, "Failed to initialize Winsock.", "Error", MB_ICONERROR);
        return 1;
    }

    // সার্ভার সাইড socket তৈরী এবং না হলে এরর মেসেজ প্রিন্ট
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {

        // ফেইল হলে এরর মেসেজ প্রিন্ট করা
        MessageBox(NULL, "Could not create socket.", "Error", MB_ICONERROR);

        // Winsock সম্পর্কিত তথ্য মুছে ফেলা
        WSACleanup();

        return 1;
    }

    /* server socker-এর address family
            হিসেবে IPv4 সেট করা */
    server.sin_family = AF_INET;

    // কোনো ব্যবহারযোগ্য নেটওয়ার্ক ইন্টারফেসে সার্ভার IP সেট করা
    server.sin_addr.s_addr = inet_addr(SERVER_IP);

    // সার্ভার socket এ পোর্ট নম্বর সেট করা
    server.sin_port = htons(PORT);

    // রিমোট ক্লায়েন্ট সকেট-এর সাথে সংযোগ করা
    if (connect(client_socket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {

        // ফেইল হলে এরর মেসেজ প্রিন্ট করা
        MessageBox(NULL, "Connection to server failed.", "Error", MB_ICONERROR);

        // ক্লায়েন্ট সকেট বন্ধ করা
        closesocket(client_socket);

        // Winsock সম্পর্কিত তথ্য মুছে ফেলা
        WSACleanup();

        return 1;
    }

    /* ক্রমাগত মেসেজ পাওয়ার জন্য `CreateThread` কল করে
            নতুন থ্রেড শুরু করা */
    HANDLE receiveThread = CreateThread(NULL, 0, ReceiveThread, NULL, 0, NULL);

    // GUI ইনিশিয়ালাইজশন
    HINSTANCE hInstance = GetModuleHandle(NULL);

    /* মেসেজ লিস্ট থেকে সংগ্রহ করা মেসেজ স্টোর করে
    MSG ডাটা টাইপের Msg ভ্যারিয়েবল */
    MSG Msg;

    /* উইন্ডো-এর ধরণ এবং ডিজাইন  ডিফাইন করার জন্য স্ট্রাকচার */
    WNDCLASS wc = {
        .style = CS_HREDRAW | CS_VREDRAW,
        .lpfnWndProc = WindowProcedure,
        .hInstance = hInstance,
        .hCursor = LoadCursor(NULL, IDC_ARROW),
        .hbrBackground = (HBRUSH)(COLOR_WINDOW + 1),
        .lpszClassName = "ClientWindowClass",
    };

    /* উইন্ডো ক্লাসকে উইন্ডো প্রসিডিউর-এর মাঝে রেজিস্টার করা
            এবং ফেইল হলে এরর মেসেজ প্রিন্ট করা */
    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    /* মেইন উইন্ডো তৈরী করার ফাংশন এটি যেখানে `ClientWindowClass`
            দ্বারা ক্লায়েন্ট উইন্ডো ক্লাস, `WinAPI Client/Person` দ্বারা উইন্ডো টাইটেল,
    `WS_OVERLAPPEDWINDOW` দ্বারা উইন্ডো-এর ডিজাইন, `CW_USEDEFAULT,
    CW_USEDEFAULT, 480, 360` দ্বারা উইন্ডো-এর অবস্থান এবং সাইজ,
    `hInstance` দ্বারা মডিউলটির ইন্সট্যান্স সেট করা হয়েছে  */
    hwnd = CreateWindowEx(0, "ClientWindowClass", "WinAPI Client/Person", WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT, 480, 360,
                          NULL, NULL, hInstance, NULL);

    // উইন্ডো তৈরী করা ফেইল অর্থাৎ রিটার্ন  হলে এরর মেসেজ প্রিন্ট করা
    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // উইন্ডোটি ডিসপ্লে করানো
    ShowWindow(hwnd, SW_SHOWDEFAULT);

    // উইন্ডো-এর ক্লায়েন্ট এরিয়া আপডেট করা
    UpdateWindow(hwnd);

    // উইন্ডো তৈরী করার সময় ক্লায়েন্ট-এর নাম ইনপুট নেওয়া
    char clientName[50];
    printf("Enter your name: ");
    scanf("%s", clientName);

    // ক্লায়েন্ট নাম সেট করা
    SetClientName(clientName);

    // GUI কন্ট্রোল তৈরী করা
    CreateControls(hwnd);

    // `GetMessage` ব্যবহার করে মেসেজ কিউ থেকে মেসেজ রিসিভ করা
    while (GetMessage(&Msg, NULL, 0, 0) > 0) {

        // কীবোর্ড মেসেজকে ক্যারেক্টার মেসেজে পরিণত করে
        TranslateMessage(&Msg);

        // মেসেজেকে উইন্ডো প্রসিডিউর এ পাঠায় প্রসেস হওয়ার জন্য
        DispatchMessage(&Msg);
    }

    // Thread-এর কাজ শেষ হওয়ার জন্য অপেক্ষা করা
    WaitForSingleObject(receiveThread, INFINITE);

    // ক্লায়েন্ট সকেট বন্ধ করা
    closesocket(client_socket);

    // Winsock সম্পর্কিত তথ্য মুছে ফেলা
    WSACleanup();

    return 0;
}



এই প্রজেক্টটি বিল্ড এবং রান আমরা দুই ভাবে করতে পারি এবং এই দুই পদ্ধতি সম্পর্কেই আমার জানবো। কিন্তু প্রজেক্টটি বিল্ড করার পূর্ব শর্ত হিসেবে আমরা আমাদের 
কম্পাইলার সিস্টেমে একটি নতুন লিংকার যুক্ত করে নেই চলো শুরুতেই। এই কাজটি আমরা নিচে দেখানো উপায়ে করতে পারি -

![Image Alt text](/project-4-img/1.png)


কোডব্লকস-এর সেটিং মেনুতে ক্লিক করে compiler অপশনে যাবো। তারপর নিচের মতো উইন্ডো আসবে।

![Image Alt text](/project-4-img/2.png)

	
এখানে লিংকার সেটিং থেকে add তে ক্লিক করলে নিউ লাইব্রেরি add করার ইনপুট বক্স আসবে এবং এখানে আমরা আমাদের প্ৰয়োজনীয় ws2_32 লাইব্রেরিটি অ্যাড করে নিবো নিচের মতো করে -     

![Image Alt text](/project-4-img/3.png)


এখানে OK অপশনগুলোতে ক্লিক করা শেষে লিংক লাইব্রেরিটি আমাদের কম্পাইলার সিস্টেমে যুক্ত হয়ে যাবে নিচের মতো করে।

![Image Alt text](/project-4-img/4.png)


এখন আমরা একে একে server.c এবং client.c ফাইলদের বিল্ড এবং রান করবো। শুরুতে আমরা যেই বিল্ড এবং রান পদ্ধতি নিয়ে আগাবো তা হলো কোডব্লকস দ্বারা। 


কোডক্লক দ্বারা server.c এবং client.c ফাইলদের বিল্ড করা:
-----------------------------------------------------------
এই ধাপে আমরা আমাদের রেগুলার প্রোগ্রাম বিল্ড করার উপায়েই এই ২টি ফাইলে পর পর বিল্ড অর্থাৎ কম্পাইল করবো। 


কোডক্লক দ্বারা server.c ফাইল রান করা:  
------------------------------------------------
এখানেও server.c আমরা আমাদের রেগুলার প্রোগ্রাম রান করার মতোই রান করবো কিন্তু রান হওয়ার পর এক্সেকিউশন উইন্ডোটিকে আমার ক্লোস করবো না। এভাবেই রেখে দিবো। 
যতক্ষণ সার্ভার এমন রান অবস্থায় থাকবে ততক্ষনই আমরা এই সার্ভার-এর সাথে আমাদের ক্লায়েন্ট-এর কানেকশন তৈরী করতে পারবো। প্রথম বার server.c ফাইলটি রান করার সময় 
আমাদের কাছে নিচের মতো পারমিশন চাইতে পারে যেখানে আমরা allow করে দিবো অপসন।  

![Image Alt text](/project-4-img/5.png)


এখানে allow করার পর সার্ভার রান হয়ে যাবে নিচের মতো করে -  

![Image Alt text](/project-4-img/6.png)


client.c ফাইল রান করা:  
--------------------------
যেহেতু কোডব্লকস-এর এক্সেকিউশন উইন্ডোকে আমরা ইতিমধ্যেই ব্যাস্ত (Engase) করে রেখেছি সার্ভার-এর রান দ্বারা তাই আমরা এখন আমাদের ইচ্ছেমতো সংখ্যক ক্লায়েন্ট উইন্ডো নিবো 
client.c-এর এক্সেকিউশন ফাইলকে সরাসরি ওপেন করে। এর জন্য আমরা এখন আমাদের প্রজেক্ট ডিরেক্টরিতে যাই।  

![Image Alt text](/project-4-img/7.png)


এখানে client.exe ফাইলটিতে ডাবল ক্লিক করলে নিচের মতো এক্সেকিউশন স্ক্রিন আসবে এবং সাথে একটি উইন্ডো ওপেন হবে।  

![Image Alt text](/project-4-img/8.png)


এখানে আমরা আমাদের ইচ্ছে মতো ক্লায়েন্ট নাম যেমন আমি এখানে দিয়েছি Rahim-এর মতো করে ইনপুট নিয়ে এন্টার ক্লিক করলে এক্সেকিউশন-এর সময় ওপেন হওয়া উইন্ডোটি নিচের 
মতো দেখাবে যা হলো এই ক্লায়েন্ট (Rahim)-এর জন্য মেসেজ আদান প্রদান-এর সারফেস।

![Image Alt text](/project-4-img/9.png)


এখন দ্বিতীয় ক্লায়েন্ট নেওয়া জন্য client.exe ফাইলটিতে ডাবল ক্লিক করে একই কাজটি আমরা পুনরায় করবো। নিচের মতো নতুন এক্সেকিউশন স্ক্রিন আসলে আমরা নতুন একটি ক্লায়েন্ট নাম ইনপুট নেই -    

![Image Alt text](/project-4-img/10.png)


এখানে Karim লিখে এন্টার ক্লায়েন্ট করলে নিচের মতো আবার একটি মেসেজ আদান প্রদান-এর উইন্ডো আসবে।    

![Image Alt text](/project-4-img/11.png)


যতক্ষণ পর্যন্ত আমরা ক্লায়েন্ট নাম সেট না করবো ততক্ষন এই উইন্ডোগুলো নিচের মতো দেখায় –

![Image Alt text](/project-4-img/12.png)


এভাবে আমাদের ২টি ক্লায়েন্ট-এর জন্য সারফেস (window) ঠিক ভাবে আসে গেলো। আমরা চাইলে একই উপায়ে আরো ক্লায়েন্ট নিতে পারি কমিউনিকেশন গ্রুপে। 
এখন তাহলে আমরাদের পরবর্তী কাজ হবে মেসেজ পাঠিয়ে চেক করা যে, এপ্লিকেশনটি সঠিক ভাবে লাখ করছে কিনা! 
চলো তাহলে সেটাই দেখে নেই -   

![Image Alt text](/project-4-img/13.png)


তারমানে আমরা ঠিক ভাবে কমিউনিকেশন করতে পারলাম প্রজেক্টটি রান করে। এখন আমাদের প্রজেক্টটি যদি 8080 পোর্ট-এর জন্য কাজ না করে থাকে তাহলে আমরা 
আমাদের ইচ্ছে মতো পোর্ট 8000, 12345 এইরকম সেট করে দিতে পারি আমাদের প্রোগ্রামের শুরুতে এভাবে -

#define PORT 12345 


এই পোর্ট সেট-এর কাজটি আমরা server.c এবং client.c দুই ফাইলের শুরুতেই দেখতে পারবো আর আমাদের শুধু পোর্ট নম্বরটি পরিবর্তন করে দিতে হবে। 
তারপর আবার ফাইলগুলো বিল্ড এবং রান করতে হবে।   



এখন আমরা দেখে নেই যে, কিভাবে আমরা কোডব্লকস ছাড়া কম্যান্ড প্রম্প্ট (cmd) ব্যবহার করে এই প্রজেক্টটি কম্পাইল এবং রান করতে পারবো।

কম্যান্ড প্রম্প্ট (cmd) ব্যবহার করে server.c এবং client.c ফাইলদের বিল্ড করা:
-------------------------------------------------------------------------------

শুরুতে আমার আমাদের কম্পিউটারের সার্চ বার এ cmd লিখে এন্টার দেই নিচের মতো করে –

![Image Alt text](/project-4-img/14.png)


এখানে এন্টার ক্লিক করলে নিচের মতো কম্যান্ড উইন্ডো আসবে -  

![Image Alt text](/project-4-img/15.png)


এখানে আমরা এই কম্যান্ড উইন্ডোতে আমাদের প্রজেক্ট ডিরেক্টরিতে যাবো cd C:\Users\nibed\Documents\Project-4 কমান্ডটি লিখে এন্টার দিয়ে। 
তোমাদের জন্য এই পাথ নামটি (C:\Users\nibed\Documents\Project-4) ভিন্ন হতে পারে। এখন এই কম্যান্ড উইন্ডোটি নিচের মতো দেখাবে -  

![Image Alt text](/project-4-img/16.png)


এখন server.c ফাইলটিকে কম্পাইল করার জন্য gcc -o server server.c -lws2_32 কমান্ডটি লিখে এন্টার দেই –

![Image Alt text](/project-4-img/17.png)


এখন client.c ফাইলটিকে কম্পাইল করার জন্য gcc -o client client.c -lws2_32 কমান্ডটি লিখে এন্টার দেই -  

![Image Alt text](/project-4-img/18.png)


তার মানে আমাদের এই ২টি ফাইল কম্পাইল হয়ে গেলো। এখন আমরা এই কম্যান্ড উইন্ডোতেই সার্ভার ফাইলকে রান করবো।


কম্যান্ড প্রম্প্ট (cmd) ব্যবহার করে server.c ফাইল রান করা:
----------------------------------------------------------
server.exe এই কমান্ডটি দিয়ে আমরা সার্ভার ফাইলটি রান করবো নিচের মতো করে এবং এই উইন্ডোটি আমরা ক্লোস করবো না।

![Image Alt text](/project-4-img/19.png)


কম্যান্ড প্রম্প্ট (cmd) ব্যবহার করে client.c ফাইল রান করা:
---------------------------------------------------------
এখন ক্লায়েন্ট ফাইল রান করার জন্য নতুন একটি কম্যান্ড উইন্ডো নিবো পূর্বের মতো করে এবং সেই উইন্ডোতেও আমরা আমাদের প্রজেক্ট ডিরেক্টরিতে যাবো। 
এরপর elient.exe কম্যান্ড দিয়ে ক্লায়েন্ট ফাইলকে রান করবো নিচের মতো করে এবং এখানে ক্লায়েন্ট নাম ইনপুট নিলে আমাদের জন্য মেসেজ আদান-প্রদান সারফেস তৈরী হবে।   

![Image Alt text](/project-4-img/20.png)


এভাবে আমরা যতগুলো ক্লায়েন্ট চাই তাদের জন্য বার বার ক্লায়েন্ট ফাইলটিকে রান করবো কম্যান্ড দিয়ে এবং রান করার সময় সেই ক্লায়েন্ট গুলোর নাম ডিফাইন করে দিবো।
