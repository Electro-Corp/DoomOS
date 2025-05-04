/*
    VGA Handler
*/
#include "vga.h"
#define WIDTH 80
#define HEIGHT 25
// Current row
int debug = 0;
// Lines
char charLines[HEIGHT][256];
// Framebuffer adress
static char* const fb = (char*)(0xb8000);
static int strlen(char *str);
char* tmp = "                                                                              ";
void clear(){
  row = 0;
  // Clear the terminal
  for(int i = 0; i < HEIGHT; i++){
      noSavePrint(tmp);
  }
  row = 0;
}

void initTerminal(){
    clear();
    
    // Disable cursor
    outb(0x3D4, 0x0A);
  	outb(0x3D5, 0x20);
}


/*
    Print to the terminal
*/
void kprintf(char *string, ...){
  //va_list va; 
  strcpy(charLines[row], string);
  int x = 0, rowDoNot = 0;
  for(int i = 0; i < strlen(string); i++){
    if(string[i] == '\\' && string[i+ 1] == 'r'){
      rowDoNot = 1;
      i+=1;
      continue;
    }
    charAt(string[i], i, row, 0xC);
  }
  if(!rowDoNot)
    row++;
  if(row + 1 > HEIGHT){
    // Lets shift everything (horribly inefficent)
    clear();
    for(int c = 0; c < HEIGHT - 1; c++){
      kprintf(charLines[c + 1]);
      strcpy(charLines[c + 1], tmp);
    }
  }
  
}

void noSavePrint(char* string){
  for(int i = 0; i < strlen(string); i++){
    charAt(string[i], i, row, 0x7);
  }
  row++;
}
void dkprintf(char* string){
    if(debug == 1)
        kprintf(string);
}

void charAt(char c, int x, int y, unsigned char color){
  int position = 2 * x + 160 * y;
  fb[position] = c;
  fb[position+1] = color;
}


