#include <linux/uaccess.h>
#include "devpal_abi_armv8a_aarch64.h"
#include <linux/printk.h>
#include "pal/aarch64/smc_inline.h"

long handle_devpal_ioctl_smc(struct smc_operands * user_ops)
{

    struct smc_operands kern_ops = {0};
    struct smc_operands output = {0};

    if (copy_from_user(&kern_ops, user_ops, sizeof(struct smc_operands)))
        return -1;

    output = pal_execute_smc_inline(&kern_ops);

    kern_ops.out.X0 = output.out.X0;
    kern_ops.out.X1 = output.out.X1;
    kern_ops.out.X2 = output.out.X2;
    kern_ops.out.X3 = output.out.X3;
    kern_ops.out.X4 = output.out.X4;
    kern_ops.out.X5 = output.out.X5;
    kern_ops.out.X6 = output.out.X6;
    kern_ops.out.X7 = output.out.X7;
    kern_ops.out.X8 = output.out.X8;
    kern_ops.out.X9 = output.out.X9;
    kern_ops.out.X10 = output.out.X10;
    kern_ops.out.X11 = output.out.X11;
    kern_ops.out.X12 = output.out.X12;
    kern_ops.out.X13 = output.out.X13;
    kern_ops.out.X14 = output.out.X14;
    kern_ops.out.X15 = output.out.X15;
    kern_ops.out.X16 = output.out.X16;
    kern_ops.out.X17 = output.out.X17;

    if (copy_to_user(user_ops, &kern_ops, sizeof(struct smc_operands)))
        return -1;

    return 0;
}
