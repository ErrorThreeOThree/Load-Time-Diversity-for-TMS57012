#ifndef _SOC_H_
#define _SOC_H_

/** @brief Number of EMAC instances                                           */
#define SOC_EMAC_PER_CNT     

/** @brief Number of MDIO instances                                           */
#define SOC_MDIO_PER_CNT                    1

/** @brief Peripheral Instance of EMAC instances                              */
#define SOC_EMAC                            (0)

/** @brief Peripheral Instance of MDIO instances                              */
#define SOC_MDIO                            (0)

/** @brief Base address of EMAC memory                                        */
#define SOC_EMAC_DSC_CTRL_MOD_RAM           (0xFC520000)
#define SOC_EMAC_DSC_CTRL_MOD_REG           (0xFCF78000)
#define SOC_EMAC_DSC_CONTROL_REG            (0xFCF78800)
#define SOC_MDIO_0_REGS                     (0xFCF78900)

/** MDIO User Access */
#define MDIO_USERACCESS0a        *( volatile Uint32* )( SOC_MDIO_0_REGS + 0x80 )

/** MDIO Control */
#define MDIO_CONTROLa            *( volatile Uint32* )( SOC_MDIO_0_REGS + 0x04 )




/** @brief Base address of USB Device Controller peripheral registers */
#define CSL_USBF_1_REGS             (0xFFFB4000u)

/** @brief Base address of USB Device Host peripheral registers */
#define CSL_USBHC_1_REGS            (0xFFFBA000u)

/** @brief Base address of USB OTG peripheral registers */
#define CSL_USBOTG_1_REGS           (0xFFFB0400)

/** @brief Peripheral Instance of USB Device Controller  */
#define CSL_USBF        (0) /** Instance of USBF  */

/** @brief Peripheral Instance of USB Host Controller  */
#define CSL_USBHC        (0) /** Instance of USBHC  */

/** @brief Peripheral Instance of USB OTG */
#define CSL_USBOTG       (0) /** Instance of USBOTG  */

/** @brief Number of USB Device Controller instances */
#define CSL_USBF_CNT                 1

#endif  /* _SOC_H_ */
