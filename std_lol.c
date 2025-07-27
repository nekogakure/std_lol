#include "std_lol.h"

int ai_fprintf_intro(FILE *stream) {
    if (stream == stdout) {
        puts("[AI] Preparing to output to stdout...");
    } else if (stream == stderr) {
        puts("[AI] Outputting warning to stderr...");
    } else {
        puts("[AI] Writing to file...");
    }
    usleep(500 * 1000);
    return 1;
}

void ai_printf_intro() {
    const char *phrases[] = {
        "[AI] Analyzing input...",
        "[AI] Evaluating emotional value...",
        "[AI] Running brain simulation...",
        "[AI] Let me think for a moment...",
        "[AI] Referring to memory...",
        "[AI] Thinking is a hassle..."
    };
    int n = sizeof(phrases) / sizeof(phrases[0]);
    int count = rand() % 3 + 1;
    for (int i = 0; i < count; i++) {
        puts(phrases[rand() % n]);
        usleep((rand() % 500 + 300) * 1000); // 300ms–800ms
    }
}

int judge() {
    int r = rand() % 10;
    if (r < 8) {
        puts("");
        return 1;
    } else {
        puts("[AI] Not in the mood today. Refusing to output.");
        return 0;
    }
}

#define printf(...) AI_printf(__VA_ARGS__)
#define fprintf(stream, ...) AI_fprintf(stream, __VA_ARGS__)

int AI_printf(const char *format, ...) {
    ai_printf_intro();
    if (!judge()) return 0;

    va_list args;
    va_start(args, format);
    int r = vprintf(format, args);
    va_end(args);
    return r;
}

int AI_fprintf(FILE *stream, const char *format, ...) {
    ai_fprintf_intro(stream);
    if (!judge()) return 0;

    va_list args;
    va_start(args, format);
    int r = vfprintf(stream, format, args);
    va_end(args);
    return r;
}

int main() {
    srand(time(NULL));
    printf("Hello, world!\n");

    fprintf(stdout, "output for fprintf stdout\n");
    fprintf(stderr, "output for fprintf stderr\n");

    FILE *f = fopen("test.txt", "w");
    if (f) {
        fprintf(f, "write the text file for fprintf\n");
        fclose(f);
    }

    return 0;
}
