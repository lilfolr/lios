#ifndef SCREEN_H_
#define SCREEN_H_

#define LINES 25
#define COLUMNS_IN_LINE 80
#define BYTES_FOR_EACH_ELEMENT 2
#define SCREENSIZE BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE * LINES

void clear_screen(void);
void kprint(const char *str);
void kprint_newline(void);

#endif // SCREEN_H_
