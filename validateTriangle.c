#include<stdio.h>
#include<assert.h>

const char* isValidTriangle(long long int a, long long int b, long long int c) {
   
  if((a < b+c) && (b < a+c) && (c < a+b)) {
    return "Valid";
  }
  else {
    return "Not Valid";
  }
}

int main() {
    
    struct TestCase {
        long long int a, b, c;
        const char* expected;
    } testCases[] = {
        {0, 0, 0, "Not Valid"},
        {1, 2, 3, "Not Valid"},
        {3, 4, 5, "Valid"},
        {10, 1, 1, "Not Valid"},
        {1, 1, 1, "Valid"},
        {5, 5, 9, "Valid"},
        {7, 10, 5, "Valid"},
        {1000000000, 1000000000, 1000000000, "Valid"},
        {1000000000, 1, 1, "Not Valid"}
    };

    
    int totalTests = sizeof(testCases) / sizeof(testCases[0]);

    
    for (int i = 0; i < totalTests; i++) {
        const char* result = isValidTriangle(testCases[i].a, testCases[i].b, testCases[i].c);
        printf("Test Case %d\n", i+1);
        printf("Expected Output: %s\nActual Output: %s\n", testCases[i].expected, result);
        assert(result == testCases[i].expected);
        printf("Passed\n\n", i + 1);
    }

    printf("All test cases passed successfully.\n");
    return 0;
}
