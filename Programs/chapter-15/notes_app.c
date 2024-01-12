#include<gtk/gtk.h> //এটা দিয়েছি যেন আমরা gtk ব্যবহার করতে পারি
#include<time.h> // যেন সময়সংক্রান্ত কাজ করতে পারি

/* টেক্সট ইনপুট নেওয়ার জন্য ভ্যারিয়েবল, এখানে text_view
আগে * দেওয়া হয়েছে যেন GtkWidget এর তথ্য text_view-এ
স্টোর হয়। এখানে যেই GtkWidget ব্যবহার করা হয়েছে এটা মূলত এই জন্য */
GtkWidget *text_view;

/* ডেস্কটপ এপ্লিকেশনটির উইন্ডো তৈরী হওয়ার জন্য ভ্যারিয়েবল,
আরেকটা ভ্যারিয়েবলে আবার নিলাম এই কারণে */
GtkWidget *window;

/* এই ফাংশনটি তৈরি করা হয়েছে যেন এটা ইউজারের দেওয়া লেখা
একটি txt ফাইলে সেভ করে এবং সেভ করার ক্ষেত্রে সময় অনুসারে
একটা নাম দিয়ে দেয় যেন আমরা বুঝতে পারি কোনটা কোন দিনের।  */
void save_note() {

    /* টেক্সট ভিউ থেকে টেক্সট বাফার পুনরুদ্ধার করা,এখানে বাফার
            হলো একটি ডাটা স্ট্রাকচার যা টেক্সটে ক্যারেক্টার এর ক্রম ধরে রাখে */
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    // টেক্সট বাফারের পুনরাবৃত্তির শুরু এবং শেষ ডিফাইন করা
    GtkTextIter start, end;
    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);

    // শুরু এবং শেষ পুনরাবৃত্তি ব্যবহার করে বাফার থেকে নোট পুনরুদ্ধার করা
    gchar *text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

    // বর্তমান সময় ডিফাইন করা
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char filename[64];

    // বর্তমান সময় দ্বারা জেনারেট হওয়া টাইমস্ট্যাম্প দিয়ে ফাইল নাম নেওয়া
    strftime(filename, sizeof(filename), "%Y-%m-%d_%H-%M-%S", tm);

    // "notes/" ডিরেক্টরি নাম দিয়ে পাথ তৈরী করা
    char path[128] = "notes/";

    // ফাইল এর নামের সাথে ফাইল পাথ এবং টাইপ যুক্ত করা
    strcat(path, filename);
    strcat(path, ".txt");

    // নোট লেখার জন্য ফাইল ওপেন করা
    FILE *file = fopen(path, "w");

    if (file != NULL) {
        // ফাইলটি সঠিকভাবে ওপেন হলে নোট প্রিন্ট করা যাবে
        fprintf(file, "%s", text);

        // কাজ শেষে ফাইলটি বন্ধ করে দেওয়া
        fclose(file);
    } else {
        // // ফাইলটি সঠিকভাবে ওপেন না হলে এরর প্রিন্ট করা যাবে
        g_print("Error creating the file.");
    }
}

int main(int argc, char *argv[]) {
    //কমান্ড লাইন আর্গুমেন্ট দ্বারা GTK ইনিশিয়ালাইজ করা
    gtk_init(&argc, &argv);

    // একটি পপ-আপ উইন্ডো হিসাবে প্রধান অ্যাপ্লিকেশন উইন্ডো তৈরি করা
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // উইন্ডোটির ডিফল্ট সাইজ সেট করে দেওয়া
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);

    /* এপ্লিকেশন উইন্ডোটিকে বন্ধ করার জন্য উইন্ডো ডেস্ট্রয় ইভেন্টটিকে gtk_main_quit
           ফাংশনের সাথে যুক্ত করে যাতে করে GTK এর কাজের অংশ থেকে তা বের হয়ে যায় */
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // উপাদানগুলির মধ্যে 5 পিক্সেল ব্যবধান সহ একটি ভার্টিক্যাল বক্স লেআউট তৈরি করা
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    // একটি নতুন টেক্সট ভিউ তৈরি করা
    text_view = gtk_text_view_new();

    // টেক্সট ভিউটিকে ভার্টিক্যাল বক্সে প্যাক করা এবং এটিকে সকল দিকে প্রসারিত হতে দেওয়া
    gtk_box_pack_start(GTK_BOX(vbox), text_view, TRUE, TRUE, 0);

    // সেভ নাম দিয়ে একটি বাটন তৈরী করা
    GtkWidget *save_button = gtk_button_new_with_label("Save");

    // বাটনে ক্লিক করার সংকেতটিকে save_note ফাংশনের সাথে সংযুক্ত করা
    g_signal_connect(save_button, "clicked", G_CALLBACK(save_note), NULL);

    // সেভ বাটনটিকে ভার্টিক্যাল বক্সে এর শেষে প্যাক করা
    gtk_box_pack_end(GTK_BOX(vbox), save_button, FALSE, FALSE, 0);

    // ভার্টিক্যাল বক্সটিকে উইন্ডোতে যুক্ত করা
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // // উইন্ডোতে থাকা সকল উপাদানগুলোকে ডিসপ্লে করা
    gtk_widget_show_all(window);

    // GTK ফাংশন কল
    gtk_main();

    return 0;
}
