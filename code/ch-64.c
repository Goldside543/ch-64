// below is an example implementation of CH-64 (CrappyHash)
// 

#include <stdio.h>
#include <stdlib.h>

int hash_value(int val) {
    val ^= val >> 16;
    val *= 0x85ebca6b;
    val ^= val >> 13;
    val *= 0xc2b2ae35;
    val ^= val >> 16;
    return val;
}

void verify_hash(int original, int user_hash) {
    // Hash the original value
    long long computed_hash = hash_value(original);
    
    // Compare the computed hash with the user-provided hash
    if (computed_hash == user_hash) {
        printf("Verification succeeded. The numbers match.\n");
    } else {
        printf("Verification failed. The numbers do not match.\n");
    }
}

void create_hash() {
    long long original_value;
    
    // Get the original value from the user
    printf("Enter the number to create a hash: ");
    scanf("%lld", &original_value);
    
    // Hash the value and display the result
    long long created_hash = hash_value(original_value);
    printf("The created hash for %lld is: %lld\n", original_value, created_hash);
}

void menu() {
    int choice;

    // Display the menu
    printf("Select an option:\n");
    printf("1. Create a hash\n");
    printf("2. Verify a hash\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            create_hash();
            break;
        case 2:
            {
                long long original_value, user_hash;
                
                // Get the original value and user-provided hash for verification
                printf("Enter the original number to verify the hash: ");
                scanf("%lld", &original_value);
                printf("Enter the hash to verify: ");
                scanf("%lld", &user_hash);
                
                verify_hash(original_value, user_hash);
            }
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main() {
    // Run the menu in a loop until the user exits
    while(1) {
        menu();
    }

    return 0;
}
