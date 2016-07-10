#include <stdio.h>
#include <stdlib.h>

/* How to compile?
   $ gcc -c99 triangles.c -o triangles 
*/

void print_n(char c, int n) {
  for(int step=1; step<=n; step++){
    printf("%c", c);
  }
}

void increasing_left(int height) {
  /*
    1 => print_n('*', 1) => *
    2 => print_n('*', 2) => **
    3 => ***
    4 => ****
   */
  int i;
  for(i=1; i<=height; i++){
    print_n('*', i);
    printf("\n");
  }
}

void increasing_right(int height) {
  /*
    height = 3
    _ _ _ * : spaces = height-1 = 3; asteriscs = 1
    _ _ * * : spaces = height-2 = 2; asteriscs = 2
    _ * * * : spaces = height-3 = 1; asteriscs = 3
    * * * * : spaces = height-4 = 0; asteriscs = 4
    spaces => (height-i) ; asteriscs => i
   */
  for(int i=1; i<=height; i++){
   /* printf("i = %d; spaces= %d; asteriscs = %d\n", i, height-i, i);*/
    print_n(' ', height-i);
    print_n('*', i);
    printf("\n");
  }
}


void decreasing_right(int height, int left_padding) {

  /* 
     
     height = 4
   * * * * : s = 0; * = height - 0 = 4
   - * * * : s = 1; * = height - 1 = 3
   - - * * : s = 2; * = height - 2 = 2
   - - - * : s = 3; * = height - 3 = 1
   s => i ; * = height - i

   */

  for(int i= 0; i<=height; i++) {
   /* printf("%d, s = %d, * = %d\n", i, i-1, height+1-i);*/
    print_n(' ', left_padding);
    print_n(' ', i);
    print_n('*', height-i);
    printf("\n");
  }
}
void symmetric_right(int height) {
  increasing_right(height);
  decreasing_right(height-1, 1);

}


void decreasing_left(int height){
  int i;
  for(i=height; i>=1; i--){
    print_n('*', i);
    printf("\n");
  }
}

void symmetric_left(int height) {
  increasing_left(height-1);
  decreasing_left(height);
}

void symmetric_bottom(int height) {
  /* 
     height = 4
     _ _ _ * \n       : s= height - 1 = 3 ; * = 2*0 + 1 = 1
     _ _ * * * \n     : s= height - 2 = 2 ; * = 2*1 + 1 = 3
     _ * * * * * \n   : s= height - 3 = 1 ; * = 2*2 + 1 = 5
     * * * * * * * \n : s= height - 4 = 0 ; * = 2*3 + 1 = 7
     
     s = (height - i) ; * = (2i + 1)
     
   */
  for(int i=0; i<height; i++){
    /*printf("%d, s= %d, * = %d\n", i, height-1-i, 2*i+1);*/
    print_n(' ', height-1-i);
    print_n('*', 2*i+1);
    printf("\n");
  }
}

void symmetric_top(int height, int left_padding) {
  /*
    height = 4
    _ * * * * * * * \n :i=0; s= i= 0 ; * = 2*(4-0-1) + 1 = 7
    _ _ * * * * * \n   :i=1; s= i= 1 ; * = 2*(4-1-1) + 1 = 5
    _ _ _ * * * \n     :i=2; s= i= 2 ; * = 2*(4-2-1) + 1 = 3
    _ _ _ _ * \n       :i=3; s= i= 3 ; * = 2*(4-3-1) + 1 = 1

    s = i ; * = 2*(height - i - 1) + 1

   */

  for(int i= 0; i<height; i++){
    /*printf("%d, s = %d, * = %d\n", i, i, 2*(height-i-1) + 1);*/
    print_n(' ', left_padding);
    print_n(' ', i);
    print_n('*', 2*(height-i-1)+1);
    printf("\n");
  }
}

void rambo(int height) {
  symmetric_bottom(height);
  symmetric_top(height-1,1);
  
}


void print_title(char *title) {
  printf("\n------------%s-----------\n", title);
}

int main(int argc, char * argv[]){

  if (argc < 2) {
    printf("Usage: $ %s <height>\n", argv[0]);
    return -1;
  }

  for (int p=0; p<argc; ++p) {
    printf("index=%d; value=%s\n", p, argv[p]);
  }

  int height = atoi(argv[1]); /* atoi("4") => 4 (int) */

  printf("height: %d\n", height);

  print_title("increasing LEFT");
  increasing_left(height);

  print_title("decreasing LEFT");
  decreasing_left(height);

  print_title("symmetric LEFT");
  symmetric_left(height);

  print_title("increasing RIGHT");
  increasing_right(height);

  print_title("decreasing RIGHT");
  decreasing_right(height, 0);

  print_title("symmetric RIGHT");
  symmetric_right(height);

  print_title("symmetric BOTTOM");
  symmetric_bottom(height);

  print_title("symmetric TOP");
  symmetric_top(height, 0);

  print_title("rambo");
  rambo(height);
}
  
