#include "functions.hpp"

const int thread_number = 8;

bool txt_extension(char const *name)
{
    size_t len = strlen(name);
    return len > 4 && strcmp(name + len - 4, ".txt") == 0;
}

bool bin_extension(char const *name)
{
    size_t len = strlen(name);
    return len > 4 && strcmp(name + len - 4, ".bin") == 0;
}

bool so_extension(char const *name)
{
    size_t len = strlen(name);
    return len > 3 && strcmp(name + len - 3, ".so") == 0;
}

bool a_extension(char const *name)
{
    size_t len = strlen(name);
    return len > 2 && strcmp(name + len - 2, ".a") == 0;
}

void analyser_func(){
  thread myThread[thread_number];
  mutex myMutex;
  struct mntent *m;
  FILE *f;
  printf("_PATH_MOUNTED macro: %s\n", _PATH_MOUNTED);
  f = setmntent(_PATH_MOUNTED, "r");
  while ((m = getmntent(f))) {
      printf("Drive: %s  Name: %s  Options: %s\n", m->mnt_dir, m->mnt_fsname, m->mnt_opts);        
  }
  for(int i = 0; i < thread_number; i++){
    myMutex.lock();
    myThread[i] = thread(statistic_function, m);
    myMutex.unlock();
  }
  endmntent(f);
}

void statistic_function(struct mntent * m){
  int text_count = 0;
  int binary_count = 0;
  int library_count =0;
  int count = 0;
  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir (m->mnt_dir)) != NULL) {
  while ((ent = readdir (dir)) != NULL) {
    if(ent->d_type != DT_DIR){
      count++;
      if(txt_extension(ent->d_name) == true){
        text_count++;
      }
      if(bin_extension(ent->d_name) == true){
        binary_count++;
      }
      if(so_extension(ent->d_name) == true || a_extension(ent->d_name) == true){
        library_count++;
      }
    }
  }
  closedir (dir);
  }
  double result = ((double)text_count/(double)count)*100.0;
  printf("Text files - %.3lf%%\n", result);
  result = ((double)binary_count/(double)count)*100.0;
  printf("Binary files - %.3lf%%\n", result);
  result = ((double)library_count/(double)count)*100.0;
  printf("Libraries - %.3lf%%\n", result);
}
