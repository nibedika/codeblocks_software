#include<stdio.h>
#include<math.h>

int main() {
    double a, b, c;
    double d, root1, root2;

    /* ax^2 + bx + c দ্বিঘাত সমীকরণটির রুট বার
            করার জন্য  a,b এবং c এর মান ইনপুট নেওয়া */
    printf("Enter the values for a, b, c for the quadratic equation (ax^2 + bx + c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // নিশ্চায়ক d এর মান শুরুতেই ক্যালকুলেট করে নেওয়া
    d = (b*b) - (4 * a*c);

    /* নিশ্চায়ক d এর মানের উপর ভিত্তি করে
            রুট এর মান পাওয়ার সম্ভাব্যতা যাচাই  */
    if (d > 0) {
        /* নিশ্চায়ক d এর মান 0 এর বড় হলে রুট  ২টি
                      আলাদা মানের এবং বাস্তব মান পাওয়া যায়   */
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);

        // রুটগুলোর মান প্রিন্ট করা
        printf("Roots are real and distinct.\n");
        printf("Root 1 = %lf and Root 2 = %lf\n", root1, root2);
    } else if (d == 0) {
        /* নিশ্চায়ক d এর মান 0 এর সমান হলে রুট ২টি
                     একই মানের এবং বাস্তব মান পাওয়া যায় */
        root1 = -b / (2 * a);

        // রুটগুলোর মান প্রিন্ট করা
        printf("Roots are real and repeated (equal):\n");
        printf("Root 1 = Root 2 = %lf\n", root1);
    } else {
        /* নিশ্চায়ক d এর মান 0 এর ছোট হলে প্রাপ্ত রুট ২টি আলাদা
                     মানের কিন্তু বাস্তব মান এবং কাল্পনিক মান এর সমন্বয়ে গঠিত হয়  */
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-d) / (2 * a);

        // রুটগুলোর মান প্রিন্ট করা
        printf("Roots are complex (imaginary):\n");
        printf("Root 1 = %lf + %lfi\n", realPart, imaginaryPart);
        printf("Root 2 = %lf - %lfi\n", realPart, imaginaryPart);
    }

    return 0;
}

