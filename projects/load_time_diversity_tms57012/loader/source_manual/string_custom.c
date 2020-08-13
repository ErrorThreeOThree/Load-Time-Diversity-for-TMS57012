/** @file
*   @brief Source file with some functions similar to <string.h>
*   @date 19-06-07
*   @version 0.1
*
*   Source file with some functions similar to <string.h>.
*   Some parameters might be different.
*/
#include "string_custom.h"

/**
 * @brief Copies @p n bytes from @p src to @p dst
 * @param[in] dst start address
 * @param[in] src source address
 * @param[in] n number of bytes
 * @return dst same as dst
 *
 * Copies @p n bytes from @p src to @p dst.
 */
void *memcpy_custom(void *dst, const void *src, size_t i) {
    size_t n = i;
	const char *src_c = src;
	char *dst_c = dst;
	while (0 < n--) {
		dst_c[n] = src_c[n];
	}
	return dst;
}

/**
 * @brief sets @p len bytes starting at @p dst to @p val
 * @param[in] dst start address
 * @param[in] val value which will be set
 * @param[in] len number of bytes
 * @return same as dst
 *
 * Sets @p len bytes starting at @p dst to @p val.
 */
void *memset_custom(void *dst, uint8_t val, size_t len) {
    uint8_t *ptr = dst;
    while (0 < len--) {
        ptr[len] = val;
    }
    return dst;
}
