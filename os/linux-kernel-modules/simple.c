#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <linux/jiffies.h>
#include <asm/param.h>

int simple_init(void);
void simple_exit(void);

/* This function is called when the module is loaded. */
int simple_init(void)
{
    printk(KERN_INFO "Loading Kernel Module∖n");
    printk(KERN_INFO "GOLDEN_RATIO_PRIME: %lu\n", GOLDEN_RATIO_PRIME);
    printk(KERN_INFO "JIFFIES LOAD: %lu\n", jiffies);
    return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void)
{
    printk("GDC(3300, 24): %lu\n", gcd(3300, 24));
    printk("JIFFIES UNLOAD: %lu\n", jiffies);
    printk(KERN_INFO "Removing Kernel Module∖n");
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
