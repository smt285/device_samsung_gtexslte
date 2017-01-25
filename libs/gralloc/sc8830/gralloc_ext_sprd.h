#ifndef GRALLOC_PRIV_EXT_H_
#define GRALLOC_PRIV_EXT_H_
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/ion.h>
#include "ion_sprd.h"

enum
{
	GRALLOC_USAGE_SPRD_PRIVATE		=  0x01000000,
	GRALLOC_USAGE_OVERLAY_BUFFER		=  0x03000000,
	GRALLOC_USAGE_VIDEO_BUFFER		=  0x05000000,
	GRALLOC_USAGE_CAMERA_BUFFER 		=  0x05000000,
};
#ifdef __cplusplus
extern "C" {
#endif
static inline int ion_invalidate_fd(int fd, int handle_fd)
{
	struct ion_custom_data custom_data;
	if (handle_fd < 0)
		return -EINVAL;
	custom_data.cmd = ION_SPRD_CUSTOM_INVALIDATE;
	custom_data.arg = (unsigned long)handle_fd;
	return ioctl(fd, ION_IOC_CUSTOM, &custom_data);
}

#ifdef __cplusplus
}
#endif
#endif // GRALLOC_PRIV_EXT_H_
