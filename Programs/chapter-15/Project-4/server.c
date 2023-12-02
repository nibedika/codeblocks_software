// socket সম্পর্কিত কাজের জন্য হেডার ফাইল
#include<winsock2.h>

// Windows API উইন্ডো নিয়ে কাজ করার জন্য হেডার ফাইল
#include<windows.h>

// ইনপুট আউটপুট এর কাজ করার জন্য হেডার ফাইল
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
এর সাথে  server side এর যোগাযোগ এর মাধ্যম তৈরী করা হয় */
SOCKET client_sockets[MAX_CLIENTS];

int num_clients = 0;


/* প্রোগ্রামে একটি কাজের পাশাপাশি অন্য কাজগুলো স্বাধীনভাবে করার সিস্টেম
হলো Thread procedure আর এখানে WINAPI এর Thread
procedure হিসেবে ReceiveThread ফাংশন কাজ করেছে */
DWORD WINAPI HandleClientThread(LPVOID lpParam) {

    // ক্লায়েন্ট সাইড এর জন্য socket ইনিশিয়ালাইজ করা
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

            /* কোনো ক্লায়েন্ট এর থেকে প্রাপ্ত মেসেজ কে সকল
                                ক্লায়েন্ট এর কাছে পাঠানো  */
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
                      এর স্লিপিং পিরিয়ড ডিফাইন করা হয়েছে  */
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

    // সার্ভার সাইড এর জন্য socket ইনিশিয়ালাইজ করা
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

    /* server socker এর address family
            হিসেবে IPv4 সেট করা */
    server.sin_family = AF_INET;

    // কোনো ব্যবহারযোগ্য নেটওয়ার্ক ইন্টারফেসে সার্ভার IP সেট করা
    server.sin_addr.s_addr = INADDR_ANY;

    // সার্ভার socket এ পোর্ট নম্বর সেট করা
    server.sin_port = htons(PORT);

    /* নির্দিষ্ট আইপি এড্রেস এবং পোর্ট এর সাথে সকেটকে সংযুক্ত করা
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

    // ইনকামিং সংযোগ এর জন্য অপেক্ষা করা
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

            // নতুন ক্লায়েন্ট এর জন্য সকেট ডিফাইন করা
            client_sockets[num_clients] = client_socket;

            /* ক্রমাগত মেসেজ পাওয়ার জন্য `CreateThread`
                                কল করে নতুন থ্রেড শুরু করা */
            HANDLE clientThread = CreateThread(NULL, 0, HandleClientThread, (LPVOID)(intptr_t)num_clients, 0, NULL);

            // নতুন ক্লায়েন্ট কানেকশন গ্রহণ করা
            printf("Connection accepted from client %d\n", num_clients);

            // Increment the number of clients
            ++num_clients;
        } else {
            /* সর্বাধিক সংখ্যক ক্লায়েন্ট এর চেয়ে বাড়তি ক্লায়েন্ট
                                এর জন্য কানেকশন ব্রেক করে দেওয়া  */
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
