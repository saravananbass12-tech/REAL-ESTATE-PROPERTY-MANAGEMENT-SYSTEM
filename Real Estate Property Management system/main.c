#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_PROPERTIES 100
#define INNER_WIDTH 65          /* characters between the two corner '+' signs */

// --- Colour IDs ---
enum { C_RESET, C_RED, C_GREEN, C_YELLOW, C_BLUE, C_MAGENTA, C_CYAN, C_WHITE };

// --- 1. Data Structure ---
struct Property {
    int id;
    char owner_name[50];
    char mobile_no[15];
    float area_sqft;
    int bedrooms;
    int location_type;
    float final_price;
    int is_sold;
};

struct Property properties[MAX_PROPERTIES];
int property_count = 0;
int next_id = 1001;

// --- 2. Portable Colour Layer ---
// Windows: uses the console API (works in cmd, Dev-C++, Code::Blocks)
// Linux/macOS: uses ANSI escape codes
#ifdef _WIN32
static WORD default_attr = 7;

void init_colors(void) {
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
        default_attr = info.wAttributes;
}

void set_color(int c) {
    static const WORD map[] = { 0, 12, 10, 14, 9, 13, 11, 15 };
    WORD attr = (c == C_RESET) ? default_attr : map[c];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr);
}
#else
void init_colors(void) { }

void set_color(int c) {
    static const char *map[] = {
        "\033[0m", "\033[1;31m", "\033[1;32m", "\033[1;33m",
        "\033[1;34m", "\033[1;35m", "\033[1;36m", "\033[1;37m"
    };
    printf("%s", map[c]);
}
#endif

// Print text in a colour, then reset
void cprintf(int color, const char *fmt, ...) {
    va_list args;
    set_color(color);
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    set_color(C_RESET);
}

// --- 3. Box Drawing Helpers (padding is done before colouring, so alignment is exact) ---
void print_border(void) {
    set_color(C_CYAN);
    putchar('+');
    for (int i = 0; i < INNER_WIDTH; i++) putchar('-');
    putchar('+');
    set_color(C_RESET);
    putchar('\n');
}

void print_title_border(const char *title) {
    char buf[100];
    snprintf(buf, sizeof(buf), " %s ", title);
    int len = (int)strlen(buf);
    int left = (INNER_WIDTH - len) / 2;
    int right = INNER_WIDTH - len - left;

    set_color(C_CYAN);
    putchar('+');
    for (int i = 0; i < left; i++) putchar('-');
    set_color(C_YELLOW);
    printf("%s", buf);
    set_color(C_CYAN);
    for (int i = 0; i < right; i++) putchar('-');
    putchar('+');
    set_color(C_RESET);
    putchar('\n');
}

void print_row_c(int color, const char *fmt, ...) {
    char buf[200];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    cprintf(C_CYAN, "|");
    printf(" ");
    cprintf(color, "%-*.*s", INNER_WIDTH - 2, INNER_WIDTH - 2, buf);
    printf(" ");
    cprintf(C_CYAN, "|");
    printf("\n");
}
#define print_row(...) print_row_c(C_WHITE, __VA_ARGS__)

void print_center_row(int color, const char *text) {
    int len = (int)strlen(text);
    int left = (INNER_WIDTH - len) / 2;
    int right = INNER_WIDTH - len - left;

    cprintf(C_CYAN, "|");
    printf("%*s", left, "");
    cprintf(color, "%s", text);
    printf("%*s", right, "");
    cprintf(C_CYAN, "|");
    printf("\n");
}

// --- 4. Price Calculation Function ---
float calculate_price(float area, int beds, int location) {
    float price_per_sqft;
    if (location == 1) price_per_sqft = 8000;
    else if (location == 2) price_per_sqft = 5000;
    else price_per_sqft = 2500;

    float total = (area * price_per_sqft) + (beds * 200000);
    total = total + (total * 0.05f); // 5% Tax
    return total;
}

// --- 5. Exit Summary ---
void display_exit_summary(void) {
    printf("\n");
    print_title_border("SYSTEM EXIT SUMMARY");

    if (property_count == 0) {
        print_row_c(C_YELLOW, "No properties registered in this session.");
    } else {
        struct Property last = properties[property_count - 1];
        print_row("Last Added ID : %d", last.id);
        print_row("Owner Name    : %s", last.owner_name);
        print_row("Mobile Number : %s", last.mobile_no);
        print_row_c(C_GREEN, "Total Price   : Rs. %.2f", last.final_price);
    }
    print_border();
    cprintf(C_MAGENTA, "\n~~~~~~~~~~~~~ Thank You for Using Real Estate System! ~~~~~~~~~~~~~\n\n");
}

// --- 6. Menu / Header ---
void display_header(void) {
    printf("\n");
    print_border();
    print_center_row(C_GREEN, "REAL ESTATE PROPERTY MANAGEMENT SYSTEM");
    print_center_row(C_YELLOW, "--------------------- o000 ---------------------");
    print_border();
}

void display_menu(void) {
    printf("\n");
    print_title_border("MAIN MENU");
    print_row("");
    print_row_c(C_GREEN,   "  1. Add New Property");
    print_row_c(C_BLUE,    "  2. View All Properties");
    print_row_c(C_YELLOW,  "  3. Sell Property");
    print_row_c(C_MAGENTA, "  4. View All Sold Properties");
    print_row_c(C_CYAN,    "  5. Search Property");
    print_row_c(C_RED,     "  6. Exit");
    print_row_c(C_WHITE,   "  7. Generate Property Report");
    print_row("");
    print_border();
}

// --- 7. Feature Functions ---
void add_property(void) {
    if (property_count >= MAX_PROPERTIES) {
        cprintf(C_RED, "\n[X] System Full! Cannot add more properties.\n");
        return;
    }

    struct Property p;
    p.id = next_id++;
    p.is_sold = 0;

    printf("\n");
    print_title_border("ADD NEW PROPERTY");

    cprintf(C_CYAN, "  Enter Owner Name     : ");
    scanf(" %49[^\n]", p.owner_name);

    // Mobile Number Validation
    int valid_mobile = 0;
    while (!valid_mobile) {
        cprintf(C_CYAN, "  Enter Mobile Number  : ");
        scanf("%14s", p.mobile_no);

        if (strlen(p.mobile_no) == 10) {
            valid_mobile = 1;
            for (int i = 0; i < 10; i++) {
                if (p.mobile_no[i] < '0' || p.mobile_no[i] > '9') {
                    valid_mobile = 0;
                    break;
                }
            }
        }
        if (!valid_mobile) {
            cprintf(C_RED, "  [X] Invalid! Enter a 10-digit number.\n");
        }
    }

    cprintf(C_CYAN, "  Enter Area (sq.ft)   : ");
    scanf("%f", &p.area_sqft);

    cprintf(C_CYAN, "  Enter Bedrooms       : ");
    scanf("%d", &p.bedrooms);

    // Location Validation
    int valid_loc = 0;
    while (!valid_loc) {
        cprintf(C_CYAN, "  Enter Location (1=City, 2=Suburb, 3=Village) : ");
        scanf("%d", &p.location_type);
        if (p.location_type >= 1 && p.location_type <= 3) {
            valid_loc = 1;
        } else {
            cprintf(C_RED, "  [X] Invalid Location! Choose 1, 2, or 3.\n");
        }
    }

    p.final_price = calculate_price(p.area_sqft, p.bedrooms, p.location_type);
    properties[property_count++] = p;

    printf("\n");
    print_border();
    print_row_c(C_GREEN, "[OK] Property added successfully!");
    print_row("Property ID : %d", p.id);
    print_row("Mobile No   : %s", p.mobile_no);
    print_row_c(C_YELLOW, "Total Price : Rs. %.2f", p.final_price);
    print_border();
}

void view_properties(void) {
    int shown = 0;
    printf("\n");
    print_title_border("PROPERTY LIST");
    for (int i = 0; i < property_count; i++) {
        if (properties[i].is_sold == 0) {
            print_row_c(C_GREEN, "ID:%d | %-12.12s | %s | Rs. %.2f",
                        properties[i].id, properties[i].owner_name,
                        properties[i].mobile_no, properties[i].final_price);
            shown++;
        }
    }
    if (shown == 0) print_row_c(C_YELLOW, "No properties available.");
    print_border();
}

void sell_property(void) {
    int sell_id;
    printf("\n");
    print_title_border("SELL PROPERTY");
    cprintf(C_CYAN, "  Enter Property ID to Sell: ");
    scanf("%d", &sell_id);

    int found = 0;
    for (int i = 0; i < property_count; i++) {
        if (properties[i].id == sell_id) {
            found = 1;
            if (properties[i].is_sold == 0) {
                properties[i].is_sold = 1;
                print_row_c(C_GREEN, "[OK] Success! Property ID %d marked as SOLD.", sell_id);
            } else {
                print_row_c(C_RED, "[X] Error: This property is already SOLD!");
            }
            break;
        }
    }
    if (!found) print_row_c(C_RED, "[X] Invalid ID! Property not found.");
    print_border();
}

void view_sold(void) {
    int sold_count = 0;
    printf("\n");
    print_title_border("SOLD PROPERTIES");
    for (int i = 0; i < property_count; i++) {
        if (properties[i].is_sold == 1) {
            print_row_c(C_MAGENTA, "ID:%d | %-12.12s | %s | Rs. %.2f",
                        properties[i].id, properties[i].owner_name,
                        properties[i].mobile_no, properties[i].final_price);
            sold_count++;
        }
    }
    if (sold_count == 0) print_row_c(C_YELLOW, "No properties sold yet.");
    print_border();
}

void search_property(void) {
    int search_id;
    printf("\n");
    print_title_border("SEARCH PROPERTY");
    cprintf(C_CYAN, "  Enter Property ID to Search: ");
    scanf("%d", &search_id);

    int found = 0;
    for (int i = 0; i < property_count; i++) {
        if (properties[i].id == search_id) {
            found = 1;
            print_row_c(C_GREEN, "[OK] Property Found!");
            print_row("Owner  : %s", properties[i].owner_name);
            print_row("Mobile : %s", properties[i].mobile_no);
            print_row("Area   : %.0f sq.ft", properties[i].area_sqft);
            print_row("Beds   : %d", properties[i].bedrooms);
            print_row_c(C_YELLOW, "Price  : Rs. %.2f", properties[i].final_price);
            if (properties[i].is_sold == 0)
                print_row_c(C_GREEN, "Status : Available");
            else
                print_row_c(C_RED, "Status : Sold");
            break;
        }
    }
    if (!found) print_row_c(C_RED, "[X] Property not found!");
    print_border();
}

void generate_report(void) {
    int avail = 0, sold = 0;
    for (int i = 0; i < property_count; i++) {
        if (properties[i].is_sold == 0) avail++;
        else sold++;
    }
    printf("\n");
    print_title_border("SYSTEM REPORT");
    print_row("Total Properties Registered : %d", property_count);
    print_row_c(C_GREEN,   "Available Properties        : %d", avail);
    print_row_c(C_MAGENTA, "Sold Properties             : %d", sold);
    print_row("Next Available ID           : %d", next_id);
    print_border();
}

// --- 8. Main ---
int main(void) {
    int choice;

    init_colors();
    display_header();

    while (1) {
        display_menu();

        cprintf(C_YELLOW, "\n -> Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            // Bad (non-numeric) input: clear the buffer and retry
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            cprintf(C_RED, "\n  [X] Invalid choice! Please try again.\n");
            continue;
        }

        switch (choice) {
            case 1: add_property();      break;
            case 2: view_properties();   break;
            case 3: sell_property();     break;
            case 4: view_sold();         break;
            case 5: search_property();   break;
            case 6: display_exit_summary(); return 0;
            case 7: generate_report();   break;
            default:
                cprintf(C_RED, "\n  [X] Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
