#include <stdio.h>

#define ROW 80
#define STR 25

int position();
int racket1(int left_half);
int racket2(int right_half);

int main() {
    int ball_x = ROW / 2;
    int ball_y = STR / 2;
    int ball_move_x = 1;
    int ball_move_y = 1;
    int left_half = 12;
    int right_half = 12;
    int score_1 = 0;
    int score_2 = 0;
    printf("press enter");
    
    while (1) {
        int step = position();

        if (step == 11) {
            if (left_half > 2) {
                left_half = left_half - 1;
                racket1(left_half);
            } else {
                racket1(left_half);
            }

        } else if (step == 12) {
            if (left_half < 22) {
                left_half = left_half + 1;
                racket1(left_half);
            } else {
                racket1(left_half);
            }

        } else if (step == 21) {
            if (right_half > 2) {
                right_half = right_half - 1;
                racket2(right_half);
            } else {
                racket2(right_half);
            }

        } else if (step == 22) {
            if (right_half < 22) {
                right_half = right_half + 1;
                racket2(right_half);
            } else {
                racket2(right_half);
            }

        } else if (step == 32) {
        } else if (step == -1) {
            break;
        } else if (step == 0) {
            printf("wrong input :((( ");
            break;
        } else {
        }

        printf("\033[H\033[J");
        for (int i = 0; i < STR; i++) {
            for (int j = 0; j < ROW + 1; j++) {
                if (i == 0 || i == STR - 1) {
                    printf("=");
                } else if (i == STR - 1 || j == 0) {
                    printf("|");
                } else if (j == ball_x && i == ball_y) {
                    printf("o");
                } else if (j == ROW / 2) {
                    printf(".");
                } else if (((j == 14) && (i == left_half - 1 || i == left_half || i == left_half + 1)) ||
                           ((j == 64) && (i == right_half - 1 || i == right_half || i == right_half + 1))) {
                    printf("|");
                } else {
                    printf(" ");
                }
            }

            printf("|\n");
        }

        printf("SCORE   %d    |   %d   ", score_1, score_2);

        if (ball_x == 1) {
            score_2 += 1;
            ball_x = ROW / 2;
            ball_y = STR / 2;
            if (score_2 == 21) {
                printf("\n\nplayer 2 win with 21 ochkooooo! cheers))\n\n");
                return 0;
            }
        } else if (ball_x >= ROW - 1) {
            score_1 += 1;
            ball_x = ROW / 2;
            ball_y = STR / 2;
            if (score_1 == 21) {
                printf("\n\nplayer 1 win with 21 ochkooooo! cheers))\n\n");
                return 0;
            }
        }

        if (ball_y == 1 || ball_y >= STR - 1) {
            ball_move_y = -ball_move_y;
        } else if ((ball_x == 15) &&
                   (ball_y == left_half - 1 || ball_y == left_half || ball_y == left_half + 1)) {
            ball_move_x = -ball_move_x;
        } else if ((ball_x == 63) &&
                   (ball_y == right_half - 1 || ball_y == right_half || ball_y == right_half + 1)) {
            ball_move_x = -ball_move_x;
        }

        ball_x += ball_move_x;
        ball_y += ball_move_y;
    }
}

int position() {
    char pos = getchar();
    int LF = pos;
    int sp = pos;

    int left_top;
    int left_down;
    int right_top;
    int right_down;

    if (pos == 'a' || pos == 'A') {
        left_top = 11;
        return left_top;
    }

    else if (pos == 'z' || pos == 'Z') {
        left_down = 12;
        return left_down;
    }

    else if (pos == 'k' || pos == 'K') {
        right_top = 21;
        return right_top;
    }

    else if (pos == 'm' || pos == 'M') {
        right_down = 22;
        return right_down;
    } else if (sp == 32) {
        return 32;
    } else if (LF == 10) {
        return 10;
    } else if (pos == 'q') {
        return -1;
    } else {
        return 0;
    }
}

int racket1(int left_half) { return left_half; }

int racket2(int right_half) { return right_half; }