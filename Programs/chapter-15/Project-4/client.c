// socket সম্পর্কিত কাজের জন্য হেডার ফাইল
#include<winsock2.h>

// Windows API উইন্ডো নিয়ে কাজ করার জন্য হেডার ফাইল
#include<windows.h>

// ইনপুট আউটপুট এর কাজ করার জন্য হেডার ফাইল
#include<stdio.h>


// Graphical User Interface(GUI) এর আউটপুট  বক্সকে ডিফাইন করা
#define ID_OUTPUT_BOX 101

// Graphical User Interface(GUI) এর ইনপুট  বক্সকে ডিফাইন করা
#define ID_INPUT_BOX 102

// Graphical User Interface(GUI) এর সেন্ড বাটনকে  ডিফাইন করা
#define ID_SEND_BUTTON 103

// যোগাযোগ পদ্ধতির পোর্ট ডিফাইন করা
#define PORT 12345

// সার্ভার IP ডিফাইন করা
#define SERVER_IP "127.0.0.1"

/* সর্বাধিক কত জন ক্লায়েন্ট অর্থাৎ মানুষ নিজেদের মাঝে কমিউনিকেশন
করতে পারবে তা ডিফাইন করা। এখানে আমরা আমাদের নিজেদের ইচ্ছে
মতো সংখ্যা নিতে পারবো।    */
#define MAX_CLIENTS 10


/* Windows API এর উইন্ডো হ্যান্ডেল করার জন্য HWND হলো একটি
ডাটা টাইপ এবং এখানে এই ডাটা টাইপ দিয়ে outputBox, inputBox
এবং editBox কে ডিফাইন করা হয়েছে এখানে  */
HWND outputBox;
HWND inputBox;
HWND sendButton;

/* Winsock লাইব্রেরিতে SOCKET হলো একটি ডাটা টাইপ যা দ্বারা socket
ডিফাইন করা হয়। socket দ্বারাই client side থেকে server side
এর সাথে যোগাযোগ এর মাধ্যম তৈরী করা হয় */
SOCKET client_socket;

// ক্লায়েন্ট উইন্ডো তৈরী এর সময় ক্লায়েন্ট নাম সেট করার জন্য ভ্যারিয়েবল
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


// ক্লায়েন্ট উইন্ডো তৈরী এর সময় ক্লায়েন্ট নাম সেট করার জন্য ফাংশন
void SetClientName(const char* name) {
    clientName = name;
}


// উইন্ডোতে মেসেজ ডিসপ্লে করা অর্থাৎ দেখানোর জন্য ফাংশন
void AppendMessageToWindow(HWND window, const char* message) {

    /* hOutputMutex অবজেক্ট এর সিগন্যাল স্টেট এ
           আসার জন্য অপেক্ষা করা */
    WaitForSingleObject(hOutputMutex, INFINITE);

    // // প্রাপ্ত মেসেজ outputBox এ সেট করা
    SendMessage(window, EM_SETSEL, -1, -1);

    // পুনরায় প্রাপ্ত মেসেজ outputBox এ প্রবেশ করানো
    SendMessage(window, EM_REPLACESEL, 0, (LPARAM)message);

    // নতুন প্রাপ্ত মেসেজে এর শেষ পর্যন্ত outputBox নিয়ে আসা
    SendMessage(window, EM_SCROLLCARET, 0, 0);

    // hOutputMutex অবজেক্ট এর কাজ শেষ করা
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
হলো Thread procedure আর এখানে WINAPI এর Thread
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
                      এর স্লিপিং পিরিয়ড ডিফাইন করা হয়েছে  */
        Sleep(100);
    }

    return 0;
}


/* এখানে `WindowProcedure` ফাংশন ডিক্লেয়ার করা হয়েছে।
উইন্ডোতে সেন্ড করা মেসেজেকে অপারেটিং সিস্টেম ডাটা কল করার
জন্য কল-ব্যাক ফাংশন এটি। আর callback ফাংশন বলতে ঐ সকল
ফাংশনকে বোঝায় যাদের অন্য ফাংশনে আর্গুমেন্ট আকারে পাঠানো হয়  */
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {

    // মেসেজে টাইপের উপর ভিত্তি করে switch স্টেটমেন্ট দ্বারা চেক করা
    switch (message) {

        // প্রাপ্ত মেসেজটি CREATE মেসেজ কিনা চেক করা
        case WM_CREATE: {

            // ক্লায়েন্ট অনুযায়ী ক্লায়েন্ট এর প্রাথমিক তথ্য সেট করা
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


// একটি উইন্ডো এর GUI কন্ট্রোল করার জন্য এই ফাংশনটি তৈরী করা হয়েছে
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

    /* আউটপুট বক্স এর মতোই এখানে ইনপুট বক্স তৈরী করা হয়েছে উইন্ডোতে */
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

    /* server socker এর address family
            হিসেবে IPv4 সেট করা */
    server.sin_family = AF_INET;

    // কোনো ব্যবহারযোগ্য নেটওয়ার্ক ইন্টারফেসে সার্ভার IP সেট করা
    server.sin_addr.s_addr = inet_addr(SERVER_IP);

    // সার্ভার socket এ পোর্ট নম্বর সেট করা
    server.sin_port = htons(PORT);

    // রিমোট ক্লায়েন্ট সকেট এর সাথে সংযোগ করা
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

    /* উইন্ডো এর ধরণ এবং ডিজাইন  ডিফাইন করার জন্য স্ট্রাকচার */
    WNDCLASS wc = {
        .style = CS_HREDRAW | CS_VREDRAW,
        .lpfnWndProc = WindowProcedure,
        .hInstance = hInstance,
        .hCursor = LoadCursor(NULL, IDC_ARROW),
        .hbrBackground = (HBRUSH)(COLOR_WINDOW + 1),
        .lpszClassName = "ClientWindowClass",
    };

    /* উইন্ডো ক্লাসকে উইন্ডো প্রসিডিউর এর মাঝে রেজিস্টার করা
            এবং ফেইল হলে এরর মেসেজ প্রিন্ট করা */
    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    /* মেইন উইন্ডো তৈরী করার ফাংশন এটি যেখানে `ClientWindowClass`
            দ্বারা ক্লায়েন্ট উইন্ডো ক্লাস, `WinAPI Client/Person` দ্বারা উইন্ডো টাইটেল,
    `WS_OVERLAPPEDWINDOW` দ্বারা উইন্ডো এর ডিজাইন, `CW_USEDEFAULT,
    CW_USEDEFAULT, 480, 360` দ্বারা উইন্ডো এর অবস্থান এবং সাইজ,
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

    // উইন্ডো এর ক্লায়েন্ট এরিয়া আপডেট করা
    UpdateWindow(hwnd);

    // উইন্ডো তৈরী করার সময় ক্লায়েন্ট এর নাম ইনপুট নেওয়া
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

    // Thread এর কাজ শেষ হওয়ার জন্য অপেক্ষা করা
    WaitForSingleObject(receiveThread, INFINITE);

    // ক্লায়েন্ট সকেট বন্ধ করা
    closesocket(client_socket);

    // Winsock সম্পর্কিত তথ্য মুছে ফেলা
    WSACleanup();

    return 0;
}
