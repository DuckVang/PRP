#include <stdio.h>
#include <stdlib.h>

/* The main program */

int Find_Line(char *pattern);
void Resolve_Allocation_Fail(void);

int main(int argc, char *argv[])
{

  int ret = EXIT_SUCCESS;
  // TODO - insert your code here
  if (argc < 1)
  {
    return EXIT_FAILURE;
  }
  char **text_file = NULL;

  char file_path[256];
  snprintf(file_path, sizeof(file_path), "./%s", argv[2]);
  printf("%s %s %s\n", argv[0], argv[1], file_path);

  FILE *file_ptr = fopen(file_path, "r");

  if (file_ptr == NULL)
  {
    printf("Error occurred while opening file!\n");
    exit(EXIT_FAILURE);
  }

  char ch;
  int line_count = 0;
  int char_count = 0;
  int default_line_size = 255;
  int count_realloc = 1;

  text_file[0] = malloc(default_line_size * sizeof(char));

  if (text_file[0] == NULL)
    Resolve_Allocation_Fail();

  while ((ch = fgetc(file_ptr)) != EOF)
  {
    if (char_count == default_line_size)
    {
      text_file[line_count] = realloc(text_file[line_count], default_line_size * (++count_realloc));
    }

    if (ch == '\n')
    {
      text_file[line_count][char_count] = '\0';
      text_file[++line_count] = malloc(default_line_size * sizeof(char));

      count_realloc = 1;
      char_count = 0;
      continue;
    }

    text_file[line_count][char_count++] = ch;
  }

  for (int i = 0; i < line_count; i++)
  {
    char c;
    int j = 0;
    while ((c = text_file[i][j++]) != '\0')
    {
      printf("%c", c);
    }
    printf("\n");
  }

  fclose(file_ptr);

  return ret;
}

int Find_Line(char *pattern)
{
  return 0;
}
void Resolve_Allocation_Fail(void)
{
  fprintf(stderr, "Memory allocation failed\n");
  exit(EXIT_FAILURE);
}
