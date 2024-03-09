#include <zephyr/kernel.h>
#include "zboss_api.h"
#include "zigbee_network/zigbee_init.h"

int main(void)
{
    zigbee_init();
    return 0;
}
