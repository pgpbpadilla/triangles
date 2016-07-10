#include <stdio.h>
#include <stdlib.h>


void print_n(char c, int n) {
  for(int step=1; step<=n; step++){
    printf("%c", c);
  }
  printf("\n");
}

void increasing_left(height) {
  /*
    1 => print_n('*', 1) => *
    2 => print_n('*', 2) => **
    3 => ***
    4 => ****
   */
  int i,n=4;
  for(i=1; i<=n; i++){
    print_n('*', i);
  }
}



void print_title(char *title) {
  printf("\n------------%s-----------\n", title);
}

int main(int argc, char * argv[]){

  for (int p=0; p<argc; ++p) {
    printf("index=%d; value=%s\n", p, argv[p]);
  }

  int height = atoi(argv[1]);

  printf("height: %d\n", height);

  print_title("increasing LEFT");
  increasing_left(height);

}
  
