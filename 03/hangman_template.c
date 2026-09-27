#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD_LEN 32
#define MAX_ATTEMPTS 6
#define MAX_WORDS    16

typedef enum {
    LEVEL_EASY = 1,
    LEVEL_MEDIUM,
    LEVEL_HARD
} Difficulty;

typedef struct {
    char      masked[MAX_WORD_LEN];   /* слово с '_' на месте неоткрытых букв */
    char      secret[MAX_WORD_LEN];   /* загаданное слово                     */
    int       length;                 /* длина слова                          */
    int       attempts_left;          /* сколько ошибок еще можно сделать     */
    Difficulty level;                 /* выбранный уровень                    */
    char      used[26];               /* какие буквы уже назывались           */
} GameState;

static const char *WORDS_EASY[]   = { "cat", "dog", "sun", "milk", "tree", "book" };
static const char *WORDS_MEDIUM[] = { "orange", "garden", "python", "school", "planet" };
static const char *WORDS_HARD[]   = { "algorithm", "structure", "variable", "compiler", "developer" };

static const int COUNT_EASY   = sizeof(WORDS_EASY)   / sizeof(WORDS_EASY[0]);
static const int COUNT_MEDIUM = sizeof(WORDS_MEDIUM) / sizeof(WORDS_MEDIUM[0]);
static const int COUNT_HARD   = sizeof(WORDS_HARD)   / sizeof(WORDS_HARD[0]);

/* UI */
void        print_banner(void);
Difficulty  ask_difficulty(void);
char        ask_letter(const GameState *g);

/* Инициализация игры */
void        init_game(GameState *g, Difficulty level);
const char *pick_random_word(Difficulty level);
void        build_masked_word(GameState *g);

/* Игровой цикл */
int         is_word_guessed(const GameState *g);
int         is_game_over(const GameState *g);
int         is_letter_used(const GameState *g, char c);
int         open_letter(GameState *g, char c);
void        mark_letter_used(GameState *g, char c);

/* Визуализация */
void        render(const GameState *g, const char *message);
void        draw_hangman(int wrong_attempts);
void        draw_word(const GameState *g);
void        draw_used_letters(const GameState *g);

/* main */
int         main(void);
void        play_round(void);

void print_banner(void) {
    printf("\n");
    printf("=================================\n");
    printf("         H A N G M A N           \n");
    printf("=================================\n");
}

Difficulty ask_difficulty(void) {
    //TODO
    return LEVEL_EASY;
}

char ask_letter(const GameState *g) {
    //TODO: use is_letter_used to check if the letter has already been guessed
    return 'a';
}

void init_game(GameState *g, Difficulty level) {
    memset(g, 0, sizeof(*g));
    g->level = level;
    g->attempts_left = MAX_ATTEMPTS;

    const char *word = pick_random_word(level);
    strncpy(g->secret, word, MAX_WORD_LEN - 1);
    g->length = (int)strlen(g->secret);

    build_masked_word(g);
}

const char *pick_random_word(Difficulty level) {
    //TODO: use rand()
    return WORDS_EASY[0];
}

void build_masked_word(GameState *g) {
    for (int i = 0; i < g->length; i++) {
        g->masked[i] = '_';
    }
    g->masked[g->length] = '\0';
}

int is_letter_used(const GameState *g, char c) {
    //TODO
    return 0;
}

void mark_letter_used(GameState *g, char c) {
    //TODO
}

int open_letter(GameState *g, char c) {
    //TODO: open the letter in the masked word if it exists in the secret word
    return 0;
}

int is_word_guessed(const GameState *g) {
    //TODO
    return 0;
}

int is_game_over(const GameState *g) {
    //TODO: check attempts
    return 0;
}

void draw_hangman(int wrong) {
    /* wrong = 0..6  (сколько ошибок уже сделано) */
    const char *stages[MAX_ATTEMPTS + 1] = {
        "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n",   /* 0 */
        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n",   /* 1 */
        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n",   /* 2 */
        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n",   /* 3 */
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n",  /* 4 */
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n",  /* 5 */
        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n"  /* 6 */
    };
    //TODO
}

void draw_word(const GameState *g) {
    //TODO
}

void draw_used_letters(const GameState *g) {
    //TODO
}

void render(const GameState *g, const char *message) {
    printf("\n---------------------------------\n");
    draw_hangman(MAX_ATTEMPTS - g->attempts_left);
    printf("\n");
    draw_word(g);
    draw_used_letters(g);
    if (message && *message) {
        printf(">> %s\n", message);
    }
    printf("---------------------------------\n");
}

void play_round(void) {
    Difficulty level = ask_difficulty();

    GameState game;
    init_game(&game, level);

    char message[128] = "";
    render(&game, message);

    while (!is_word_guessed(&game) && !is_game_over(&game)) {
        char c = ask_letter(&game);
        mark_letter_used(&game, c);

        if (open_letter(&game, c)) {
            snprintf(message, sizeof(message), "Letter '%c' is in the word!", c);
        } else {
            game.attempts_left--;
            snprintf(message, sizeof(message), "Letter '%c' is not in the word. Minus an attempt.", c);
        }

        render(&game, message);
    }

    if (is_word_guessed(&game)) {
        printf("\nVICTORY! The word was: %s\n", game.secret);
    } else {
        printf("\nDEFEAT! The word was: %s\n", game.secret);
    }
}

int main(void) {
    srand((unsigned)time(NULL));
    print_banner();

    char again = 'y';
    while (again == 'y' || again == 'Y') {
        play_round();
        printf("\nPlay again? (y/n): ");
        scanf(" %c", &again);
    }

    printf("See you!\n");
    return 0;
}