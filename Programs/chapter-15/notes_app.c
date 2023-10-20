#include<gtk/gtk.h>
#include<time.h>

// টেক্সট ইনপুট নেওয়ার জন্য ভ্যারিয়েবল
GtkWidget *text_view;

// ডেস্কটপ এপ্লিকেশনটির উইন্ডো তৈরী হওয়ার জন্য ভ্যারিয়েবল
GtkWidget *window;

/* এই ফাংশনটি একটি টেক্সট ফাইলে নোট সেভ করে।
এটি ফাইল থেকে নোট পুনরুদ্ধার করে, একটি টাইমস্ট্যাম্প তৈরি করে,
টাইমস্ট্যাম্পের উপর ভিত্তি করে একটি ফাইল পাথ তৈরি করে এবং ফাইলটিতে নোট লেখে */
void save_note() {

    /* টেক্সট ভিউ থেকে টেক্সট বাফার পুনরুদ্ধার করা,
            এখানে বাফার হলো একটি ডাটা স্ট্রাকচার যা টেক্সটে ক্যারেক্টার এর ক্রম ধরে রাখে */
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

    /* এপ্লিকেশন উইন্ডোটিকে বন্ধ করার জন্য উইন্ডো ডেস্ট্রয় ইভেন্টটিকে gtk_main_quit
            ফাংশনের সাথে যুক্ত করে যাতে করে GTK এর কাজের অংশ থেকে তা বের হয়ে যায় */
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // উপাদানগুলির মধ্যে 5 পিক্সেল ব্যবধান সহ একটি ভার্টিক্যাল বক্স লেআউট তৈরি করা
    GtkWidget *vbox = gtk_vbox_new(FALSE, 5);

    // প্রধান উইন্ডোতে ভার্টিক্যাল বক্স লেআউটটি যোগ করা
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // একটি নতুন টেক্সট ভিউ তৈরি করা
    text_view = gtk_text_view_new();

    // টেক্সট ভিউটিকে ভার্টিক্যাল বক্সে প্যাক করা এবং এটিকে সকল দিকে প্রসারিত হতে দেওয়া
    gtk_box_pack_start(GTK_BOX(vbox), text_view, TRUE, TRUE, 0);

    // সেভ নাম দিয়ে একটি বাটন তৈরী করা
    GtkWidget *save_button = gtk_button_new_with_label("Save");

    // বাটনে ক্লিক করার সংকেতটিকে save_note ফাংশনের সাথে সংযুক্ত করা
    g_signal_connect(save_button, "clicked", G_CALLBACK(save_note), NULL);

    // সেভ বাটনটিকে ভার্টিক্যাল বক্সে প্যাক করা
    gtk_box_pack_start(GTK_BOX(vbox), save_button, FALSE, FALSE, 0);

    // উইন্ডোতে থাকা সকল উপাদানগুলোকে ডিসপ্লে করা
    gtk_widget_show_all(window);

    // GTK ফাংশন কল
    gtk_main();

    return 0;
}

