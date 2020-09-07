

#include <fun/print_colors.h>


int main() {

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            printf(P_256_VAR_COLOR "%4u" P_256_DEFAULT, i * 16 + j, i * 16 + j);
        }
        printf("\n");
    }

    return 0;
}


