

#define release_if_not_null(ptr, releaser) if(ptr != NULL){releaser(ptr);}