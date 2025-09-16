
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include <thread>
#include <vector>

#include "xpn.h"

#define KB        (1024)
#define BUFF_SIZE (1024 * 1024)
char buffer[BUFF_SIZE];
const char *path;
int mb;
int threads;

double get_time(void) {
    struct timeval tp;
    struct timezone tzp;

    gettimeofday(&tp, &tzp);
    return ((double)tp.tv_sec + .000001 * (double)tp.tv_usec);
}

int run_test() {
    int ret, fd1;
    double t_bc, t_ac, t_bw, t_aw;
    // xpn-creat
    t_bc = get_time();

    fd1 = xpn_open(path, O_RDWR);
    if (fd1 < 0) {
        printf("Error: xpn_open('%s', %o) = %d %s\n", path, 00777, fd1, strerror(errno));
        return -1;
    }

    t_bw = get_time();

    // xpn-write
    for (int i = 0; i < mb; i++) {
        ret = xpn_write(fd1, buffer, BUFF_SIZE);
        printf("%d = xpn_write_%d(%d, %p, %lu)\n", ret, i, fd1, buffer, (unsigned long)BUFF_SIZE);
    }

    t_aw = get_time() - t_bw;

    xpn_close(fd1);
    // printf("%d = xpn_close(%d)\n", ret, fd1) ;

    t_ac = get_time() - t_bc;

    printf("Bytes; Total time (ms); Write time (ms)\n");
    printf("%f;%f;%f\n", (double)mb * BUFF_SIZE, t_ac * 1000, t_aw * 1000);

    return 0;
}

int main(int argc, char *argv[]) {
    int ret;

    if (argc < 4) {
        printf("\n");
        printf(" Usage: %s <full path> <megabytes to read> <threads>\n", argv[0]);
        printf("\n");
        printf(" Example:");
        printf(" env XPN_CONF=./xpn.conf XPN_DNS=/shared/tcp_server.dns %s /P1/test_1 2\n", argv[0]);
        printf("\n");
        return -1;
    }
    path = argv[1];
    mb = atoi(argv[2]);
    threads = atoi(argv[3]);

    // xpn-init
    ret = xpn_init();
    printf("%d = xpn_init()\n", ret);
    if (ret < 0) {
        return -1;
    }

    memset(buffer, 'a', BUFF_SIZE);
    printf("memset(buffer, 'a', %d)\n", BUFF_SIZE);

    std::vector<std::thread> v_t;
    for (int i = 0; i < threads; i++) {
        v_t.emplace_back(run_test);
    }
    for (auto &&t : v_t) {
        t.join();
    }

    // xpn-destroy
    ret = xpn_destroy();
    printf("%d = xpn_destroy()\n", ret);
    if (ret < 0) {
        return -1;
    }
}