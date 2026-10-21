#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>


// weak function -> no error if missing. Null pointer
extern int64_t addition(int64_t a, int64_t b) __attribute__((weak));
extern int64_t triangle(int64_t base, int64_t height) __attribute__((weak));

int main(int argc, char *argv[]) {
    int functions_found = 0;
    int error = 0;

    // --- Test 'addition' ---
    if (addition != NULL) {
        functions_found = 1;

        if (argc != 3) {
            fprintf(stderr, "Provide exactly two arguments!\n");
        }

        int64_t value_one = atoi(argv[1]);
	    int64_t value_two = atoi(argv[2]);
	    int64_t result = addition(value_one, value_two);
	    printf("addition(%" PRId64 ", %" PRId64 ") = %" PRId64 "\n\n", value_one,
	       value_two, result);

    
        printf("'addition' found. Running tests...\n");

        // test 1
        int64_t a1 = 5, b1 = 7, expected1 = 12;
        int64_t result1 = addition(a1, b1);
        printf("   - Test: addition(%" PRId64 ", %" PRId64 ") = %" PRId64, a1, b1, expected1);
        if (result1 == expected1) {
            printf("  -> PASS\n");
        } else {
            printf("  -> FAIL (Ergebnis: %" PRId64 ")\n", result1);
            error = 1;
        }

        // test 2
        int64_t a2 = -10, b2 = 4, expected2 = -6;
        int64_t result2 = addition(a2, b2);
        printf("   - Test: addition(%" PRId64 ", %" PRId64 ") = %" PRId64, a2, b2, expected2);
        if (result2 == expected2) {
            printf("  -> PASS\n");
        } else {
            printf("  -> FAIL (Ergebnis: %" PRId64 ")\n", result2);
            error = 1;
        }
        printf("\n");
    }

    // --- Test 'triangle' ---
    if (triangle != NULL) {
        functions_found = 1;

        if (argc != 3) {
            fprintf(stderr, "Provide exactly two arguments!\n");
        }
    
        int64_t value_one = atoi(argv[1]);
        int64_t value_two = atoi(argv[2]);
        int64_t result = triangle(value_one, value_two);
        printf("triangle(%" PRId64 ", %" PRId64 ") = %" PRId64 "\n\n", value_one,
               value_two, result);

               
        printf("'triangle' found. Running tests...\n");

        // test 1
        int64_t base1 = 10, height1 = 5, expected_tri1 = 25;
        int64_t result_tri1 = triangle(base1, height1);
        printf("   - Test: triangle(%" PRId64 ", %" PRId64 ") = %" PRId64, base1, height1, expected_tri1);
        if (result_tri1 == expected_tri1) {
            printf(" -> PASS\n");
        } else {
            printf(" -> FAIL (Ergebnis: %" PRId64 ")\n", result_tri1);
            error = 1;
        }

        // test 2
        int64_t base2 = 7, height2 = 6, expected_tri2 = 21;
        int64_t result_tri2 = triangle(base2, height2);
        printf("   - Test: triangle(%" PRId64 ", %" PRId64 ") = %" PRId64, base2, height2, expected_tri2);
        if (result_tri2 == expected_tri2) {
            printf(" -> PASS\n");
        } else {
            printf(" -> FAIL (Ergebnis: %" PRId64 ")\n", result_tri2);
            error = 1;
        }
        printf("\n");
    }

    // --- Fallback, wenn keine Funktion gefunden wurde ---
    if (!functions_found) {
        printf("❌ No functions found.\n");
        error = 1;
    }

    if (error) return 1;
    
    return 0;
}
