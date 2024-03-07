#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
char *file_path = "example.txt";
struct stat file_stat;
if (stat(file_path, &file_stat) == -1) {
perror("stat");
return 1;
}
printf("File permissions: ");
printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
printf("\n");
printf("Owner UID: %d\n", file_stat.st_uid);
printf("Group GID: %d\n", file_stat.st_gid);
if (chmod(file_path, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1) {
perror("chmod");
return 1;
}
printf("File permissions changed.\n");
perror("chown");
return 1;
}
printf("File owner and group changed.\n");
return 0;
}

