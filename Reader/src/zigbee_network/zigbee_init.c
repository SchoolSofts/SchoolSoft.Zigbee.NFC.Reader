#include "zboss_api.h"

void zigbee_init(void)
{
    zb_ret_t ret = zboss_start();
    if (ret != RET_OK)
    {
        printk("Failed to start Zigbee stack\n");
    }
}