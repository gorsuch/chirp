#ifndef CONFIG_H
#define CONFIG_H

struct config {
  char * dest_redis_host;
  int dest_redis_port;
  char * dest_redis_list;
  redisContext * dest_redis;
};

#endif
