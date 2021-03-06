/**
 * @file ksz8895_driver.h
 * @brief KSZ8895 5-port Ethernet switch
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2019 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneTCP Open.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 1.9.6
 **/

#ifndef _KSZ8895_DRIVER_H
#define _KSZ8895_DRIVER_H

//Dependencies
#include "core/nic.h"

//KSZ8895 ports
#define KSZ8895_PORT1 1
#define KSZ8895_PORT2 2
#define KSZ8895_PORT3 3
#define KSZ8895_PORT4 4

//SPI command byte
#define KSZ8895_SPI_CMD_WRITE 0x02
#define KSZ8895_SPI_CMD_READ  0x03

//KSZ8895 PHY registers
#define KSZ8895_BMCR                                0x00
#define KSZ8895_BMSR                                0x01
#define KSZ8895_PHYID1                              0x02
#define KSZ8895_PHYID2                              0x03
#define KSZ8895_ANAR                                0x04
#define KSZ8895_ANLPAR                              0x05
#define KSZ8895_LINKMD                              0x1D
#define KSZ8895_PHYSCS                              0x1F

//KSZ8895 Switch registers
#define KSZ8895_CHIP_ID0                            0x00
#define KSZ8895_CHIP_ID1                            0x01
#define KSZ8895_GLOBAL_CTRL0                        0x02
#define KSZ8895_GLOBAL_CTRL1                        0x03
#define KSZ8895_GLOBAL_CTRL2                        0x04
#define KSZ8895_GLOBAL_CTRL3                        0x05
#define KSZ8895_GLOBAL_CTRL4                        0x06
#define KSZ8895_GLOBAL_CTRL5                        0x07
#define KSZ8895_GLOBAL_CTRL6                        0x08
#define KSZ8895_GLOBAL_CTRL7                        0x09
#define KSZ8895_GLOBAL_CTRL8                        0x0A
#define KSZ8895_GLOBAL_CTRL9                        0x0B
#define KSZ8895_GLOBAL_CTRL10                       0x0C
#define KSZ8895_GLOBAL_CTRL11                       0x0D
#define KSZ8895_PD_MGMT_CTRL1                       0x0E
#define KSZ8895_PD_MGMT_CTRL2                       0x0F
#define KSZ8895_PORT1_CTRL0                         0x10
#define KSZ8895_PORT1_CTRL1                         0x11
#define KSZ8895_PORT1_CTRL2                         0x12
#define KSZ8895_PORT1_CTRL3                         0x13
#define KSZ8895_PORT1_CTRL4                         0x14
#define KSZ8895_PORT1_STAT0                         0x19
#define KSZ8895_PORT1_PSCS                          0x1A
#define KSZ8895_PORT1_LINKMD                        0x1B
#define KSZ8895_PORT1_CTRL5                         0x1C
#define KSZ8895_PORT1_CTRL6                         0x1D
#define KSZ8895_PORT1_STAT1                         0x1E
#define KSZ8895_PORT1_CTRL7_STAT2                   0x1F
#define KSZ8895_PORT2_CTRL0                         0x20
#define KSZ8895_PORT2_CTRL1                         0x21
#define KSZ8895_PORT2_CTRL2                         0x22
#define KSZ8895_PORT2_CTRL3                         0x23
#define KSZ8895_PORT2_CTRL4                         0x24
#define KSZ8895_PORT2_STAT0                         0x29
#define KSZ8895_PORT2_PSCS                          0x2A
#define KSZ8895_PORT2_LINKMD                        0x2B
#define KSZ8895_PORT2_CTRL5                         0x2C
#define KSZ8895_PORT2_CTRL6                         0x2D
#define KSZ8895_PORT2_STAT1                         0x2E
#define KSZ8895_PORT2_CTRL7_STAT2                   0x2F
#define KSZ8895_PORT3_CTRL0                         0x30
#define KSZ8895_PORT3_CTRL1                         0x31
#define KSZ8895_PORT3_CTRL2                         0x32
#define KSZ8895_PORT3_CTRL3                         0x33
#define KSZ8895_PORT3_CTRL4                         0x34
#define KSZ8895_PORT3_STAT0                         0x39
#define KSZ8895_PORT3_PSCS                          0x3A
#define KSZ8895_PORT3_LINKMD                        0x3B
#define KSZ8895_PORT3_CTRL5                         0x3C
#define KSZ8895_PORT3_CTRL6                         0x3D
#define KSZ8895_PORT3_STAT1                         0x3E
#define KSZ8895_PORT3_CTRL7_STAT2                   0x3F
#define KSZ8895_PORT4_CTRL0                         0x40
#define KSZ8895_PORT4_CTRL1                         0x41
#define KSZ8895_PORT4_CTRL2                         0x42
#define KSZ8895_PORT4_CTRL3                         0x43
#define KSZ8895_PORT4_CTRL4                         0x44
#define KSZ8895_PORT4_STAT0                         0x49
#define KSZ8895_PORT4_PSCS                          0x4A
#define KSZ8895_PORT4_LINKMD                        0x4B
#define KSZ8895_PORT4_CTRL5                         0x4C
#define KSZ8895_PORT4_CTRL6                         0x4D
#define KSZ8895_PORT4_STAT1                         0x4E
#define KSZ8895_PORT4_CTRL7_STAT2                   0x4F
#define KSZ8895_PORT5_CTRL0                         0x50
#define KSZ8895_PORT5_CTRL1                         0x51
#define KSZ8895_PORT5_CTRL2                         0x52
#define KSZ8895_PORT5_CTRL3                         0x53
#define KSZ8895_PORT5_CTRL4                         0x54
#define KSZ8895_RMII_MGMT_CTRL                      0x57
#define KSZ8895_PORT5_STAT0                         0x59
#define KSZ8895_PORT5_PSCS                          0x5A
#define KSZ8895_PORT5_LINKMD                        0x5B
#define KSZ8895_PORT5_CTRL5                         0x5C
#define KSZ8895_PORT5_CTRL6                         0x5D
#define KSZ8895_PORT5_STAT1                         0x5E
#define KSZ8895_PORT5_CTRL7_STAT2                   0x5F
#define KSZ8895_MAC_ADDR0                           0x68
#define KSZ8895_MAC_ADDR1                           0x69
#define KSZ8895_MAC_ADDR2                           0x6A
#define KSZ8895_MAC_ADDR3                           0x6B
#define KSZ8895_MAC_ADDR4                           0x6C
#define KSZ8895_MAC_ADDR5                           0x6D
#define KSZ8895_IND_ACCESS_CTRL0                    0x6E
#define KSZ8895_IND_ACCESS_CTRL1                    0x6F
#define KSZ8895_IND_DATA8                           0x70
#define KSZ8895_IND_DATA7                           0x71
#define KSZ8895_IND_DATA6                           0x72
#define KSZ8895_IND_DATA5                           0x73
#define KSZ8895_IND_DATA4                           0x74
#define KSZ8895_IND_DATA3                           0x75
#define KSZ8895_IND_DATA2                           0x76
#define KSZ8895_IND_DATA1                           0x77
#define KSZ8895_IND_DATA0                           0x78
#define KSZ8895_INT_STAT                            0x7C
#define KSZ8895_INT_MASK                            0x7D
#define KSZ8895_GLOBAL_CTRL12                       0x80
#define KSZ8895_GLOBAL_CTRL13                       0x81
#define KSZ8895_GLOBAL_CTRL14                       0x82
#define KSZ8895_GLOBAL_CTRL15                       0x83
#define KSZ8895_GLOBAL_CTRL16                       0x84
#define KSZ8895_GLOBAL_CTRL17                       0x85
#define KSZ8895_GLOBAL_CTRL18                       0x86
#define KSZ8895_GLOBAL_CTRL19                       0x87
#define KSZ8895_ID                                  0x89
#define KSZ8895_TOS_PRIO_CTRL0                      0x90
#define KSZ8895_TOS_PRIO_CTRL1                      0x91
#define KSZ8895_TOS_PRIO_CTRL2                      0x92
#define KSZ8895_TOS_PRIO_CTRL3                      0x93
#define KSZ8895_TOS_PRIO_CTRL4                      0x94
#define KSZ8895_TOS_PRIO_CTRL5                      0x95
#define KSZ8895_TOS_PRIO_CTRL6                      0x96
#define KSZ8895_TOS_PRIO_CTRL7                      0x97
#define KSZ8895_TOS_PRIO_CTRL8                      0x98
#define KSZ8895_TOS_PRIO_CTRL9                      0x99
#define KSZ8895_TOS_PRIO_CTRL10                     0x9A
#define KSZ8895_TOS_PRIO_CTRL11                     0x9B
#define KSZ8895_TOS_PRIO_CTRL12                     0x9C
#define KSZ8895_TOS_PRIO_CTRL13                     0x9D
#define KSZ8895_TOS_PRIO_CTRL14                     0x9E
#define KSZ8895_TOS_PRIO_CTRL15                     0x9F
#define KSZ8895_PORT1_CTRL8                         0xB0
#define KSZ8895_PORT1_CTRL9                         0xB1
#define KSZ8895_PORT1_CTRL10                        0xB2
#define KSZ8895_PORT1_CTRL11                        0xB3
#define KSZ8895_PORT1_CTRL12                        0xB4
#define KSZ8895_PORT1_CTRL13                        0xB5
#define KSZ8895_PORT1_RATE_LIMIT_CTRL               0xB6
#define KSZ8895_PORT1_PRIO0_IG_LIMIT_CTRL1          0xB7
#define KSZ8895_PORT1_PRIO1_IG_LIMIT_CTRL2          0xB8
#define KSZ8895_PORT1_PRIO2_IG_LIMIT_CTRL3          0xB9
#define KSZ8895_PORT1_PRIO3_IG_LIMIT_CTRL4          0xBA
#define KSZ8895_PORT1_QUEUE0_EG_LIMIT_CTRL1         0xBB
#define KSZ8895_PORT1_QUEUE1_EG_LIMIT_CTRL2         0xBC
#define KSZ8895_PORT1_QUEUE2_EG_LIMIT_CTRL3         0xBD
#define KSZ8895_PORT1_QUEUE3_EG_LIMIT_CTRL4         0xBE
#define KSZ8895_TEST1                               0xBF
#define KSZ8895_PORT2_CTRL8                         0xC0
#define KSZ8895_PORT2_CTRL9                         0xC1
#define KSZ8895_PORT2_CTRL10                        0xC2
#define KSZ8895_PORT2_CTRL11                        0xC3
#define KSZ8895_PORT2_CTRL12                        0xC4
#define KSZ8895_PORT2_CTRL13                        0xC5
#define KSZ8895_PORT2_RATE_LIMIT_CTRL               0xC6
#define KSZ8895_PORT2_PRIO0_IG_LIMIT_CTRL1          0xC7
#define KSZ8895_PORT2_PRIO1_IG_LIMIT_CTRL2          0xC8
#define KSZ8895_PORT2_PRIO2_IG_LIMIT_CTRL3          0xC9
#define KSZ8895_PORT2_PRIO3_IG_LIMIT_CTRL4          0xCA
#define KSZ8895_PORT2_QUEUE0_EG_LIMIT_CTRL1         0xCB
#define KSZ8895_PORT2_QUEUE1_EG_LIMIT_CTRL2         0xCC
#define KSZ8895_PORT2_QUEUE2_EG_LIMIT_CTRL3         0xCD
#define KSZ8895_PORT2_QUEUE3_EG_LIMIT_CTRL4         0xCE
#define KSZ8895_PORT3_CTRL8                         0xD0
#define KSZ8895_PORT3_CTRL9                         0xD1
#define KSZ8895_PORT3_CTRL10                        0xD2
#define KSZ8895_PORT3_CTRL11                        0xD3
#define KSZ8895_PORT3_CTRL12                        0xD4
#define KSZ8895_PORT3_CTRL13                        0xD5
#define KSZ8895_PORT3_RATE_LIMIT_CTRL               0xD6
#define KSZ8895_PORT3_PRIO0_IG_LIMIT_CTRL1          0xD7
#define KSZ8895_PORT3_PRIO1_IG_LIMIT_CTRL2          0xD8
#define KSZ8895_PORT3_PRIO2_IG_LIMIT_CTRL3          0xD9
#define KSZ8895_PORT3_PRIO3_IG_LIMIT_CTRL4          0xDA
#define KSZ8895_PORT3_QUEUE0_EG_LIMIT_CTRL1         0xDB
#define KSZ8895_PORT3_QUEUE1_EG_LIMIT_CTRL2         0xDC
#define KSZ8895_PORT3_QUEUE2_EG_LIMIT_CTRL3         0xDD
#define KSZ8895_PORT3_QUEUE3_EG_LIMIT_CTRL4         0xDE
#define KSZ8895_TEST2                               0xDF
#define KSZ8895_PORT4_CTRL8                         0xE0
#define KSZ8895_PORT4_CTRL9                         0xE1
#define KSZ8895_PORT4_CTRL10                        0xE2
#define KSZ8895_PORT4_CTRL11                        0xE3
#define KSZ8895_PORT4_CTRL12                        0xE4
#define KSZ8895_PORT4_CTRL13                        0xE5
#define KSZ8895_PORT4_RATE_LIMIT_CTRL               0xE6
#define KSZ8895_PORT4_PRIO0_IG_LIMIT_CTRL1          0xE7
#define KSZ8895_PORT4_PRIO1_IG_LIMIT_CTRL2          0xE8
#define KSZ8895_PORT4_PRIO2_IG_LIMIT_CTRL3          0xE9
#define KSZ8895_PORT4_PRIO3_IG_LIMIT_CTRL4          0xEA
#define KSZ8895_PORT4_QUEUE0_EG_LIMIT_CTRL1         0xEB
#define KSZ8895_PORT4_QUEUE1_EG_LIMIT_CTRL2         0xEC
#define KSZ8895_PORT4_QUEUE2_EG_LIMIT_CTRL3         0xED
#define KSZ8895_PORT4_QUEUE3_EG_LIMIT_CTRL4         0xEE
#define KSZ8895_PORT3_COPPER_FIBER_CTRL             0xEF
#define KSZ8895_PORT5_CTRL8                         0xF0
#define KSZ8895_PORT5_CTRL9                         0xF1
#define KSZ8895_PORT5_CTRL10                        0xF2
#define KSZ8895_PORT5_CTRL11                        0xF3
#define KSZ8895_PORT5_CTRL12                        0xF4
#define KSZ8895_PORT5_CTRL13                        0xF5
#define KSZ8895_PORT5_RATE_LIMIT_CTRL               0xF6
#define KSZ8895_PORT5_PRIO0_IG_LIMIT_CTRL1          0xF7
#define KSZ8895_PORT5_PRIO1_IG_LIMIT_CTRL2          0xF8
#define KSZ8895_PORT5_PRIO2_IG_LIMIT_CTRL3          0xF9
#define KSZ8895_PORT5_PRIO3_IG_LIMIT_CTRL4          0xFA
#define KSZ8895_PORT5_QUEUE0_EG_LIMIT_CTRL1         0xFB
#define KSZ8895_PORT5_QUEUE1_EG_LIMIT_CTRL2         0xFC
#define KSZ8895_PORT5_QUEUE2_EG_LIMIT_CTRL3         0xFD
#define KSZ8895_PORT5_QUEUE3_EG_LIMIT_CTRL4         0xFE
#define KSZ8895_TEST3                               0xFF

//KSZ8895 Switch register access macros
#define KSZ8895_PORTn_CTRL0(port)                   (0x00 + ((port) * 0x10))
#define KSZ8895_PORTn_CTRL1(port)                   (0x01 + ((port) * 0x10))
#define KSZ8895_PORTn_CTRL2(port)                   (0x02 + ((port) * 0x10))
#define KSZ8895_PORTn_CTRL3(port)                   (0x03 + ((port) * 0x10))
#define KSZ8895_PORTn_CTRL4(port)                   (0x04 + ((port) * 0x10))
#define KSZ8895_PORTn_STAT0(port)                   (0x09 + ((port) * 0x10))
#define KSZ8895_PORTn_PSCS(port)                    (0x0A + ((port) * 0x10))
#define KSZ8895_PORTn_LINKMD(port)                  (0x0B + ((port) * 0x10))
#define KSZ8895_PORTn_CTRL5(port)                   (0x0C + ((port) * 0x10))
#define KSZ8895_PORTn_CTRL6(port)                   (0x0D + ((port) * 0x10))
#define KSZ8895_PORTn_STAT1(port)                   (0x0E + ((port) * 0x10))
#define KSZ8895_PORTn_CTRL7_STAT2(port)             (0x0F + ((port) * 0x10))
#define KSZ8895_PORTn_CTRL8(port)                   (0xA0 + ((port) * 0x10))
#define KSZ8895_PORTn_CTRL9(port)                   (0xA1 + ((port) * 0x10))
#define KSZ8895_PORTn_CTRL10(port)                  (0xA2 + ((port) * 0x10))
#define KSZ8895_PORTn_CTRL11(port)                  (0xA3 + ((port) * 0x10))
#define KSZ8895_PORTn_CTRL12(port)                  (0xA4 + ((port) * 0x10))
#define KSZ8895_PORTn_CTRL13(port)                  (0xA5 + ((port) * 0x10))
#define KSZ8895_PORTn_RATE_LIMIT_CTRL(port)         (0xA6 + ((port) * 0x10))
#define KSZ8895_PORTn_PRIO0_IG_LIMIT_CTRL1(port)    (0xA7 + ((port) * 0x10))
#define KSZ8895_PORTn_PRIO1_IG_LIMIT_CTRL2(port)    (0xA8 + ((port) * 0x10))
#define KSZ8895_PORTn_PRIO2_IG_LIMIT_CTRL3(port)    (0xA9 + ((port) * 0x10))
#define KSZ8895_PORTn_PRIO3_IG_LIMIT_CTRL4(port)    (0xAA + ((port) * 0x10))
#define KSZ8895_PORTn_QUEUE0_EG_LIMIT_CTRL1(port)   (0xAB + ((port) * 0x10))
#define KSZ8895_PORTn_QUEUE1_EG_LIMIT_CTRL2(port)   (0xAC + ((port) * 0x10))
#define KSZ8895_PORTn_QUEUE2_EG_LIMIT_CTRL3(port)   (0xAD + ((port) * 0x10))
#define KSZ8895_PORTn_QUEUE3_EG_LIMIT_CTRL4(port)   (0xAE + ((port) * 0x10))

//MII Control register
#define KSZ8895_BMCR_RESET                          0x8000
#define KSZ8895_BMCR_LOOPBACK                       0x4000
#define KSZ8895_BMCR_FORCE_100                      0x2000
#define KSZ8895_BMCR_AN_EN                          0x1000
#define KSZ8895_BMCR_POWER_DOWN                     0x0800
#define KSZ8895_BMCR_ISOLATE                        0x0400
#define KSZ8895_BMCR_RESTART_AN                     0x0200
#define KSZ8895_BMCR_FORCE_FULL_DUPLEX              0x0100
#define KSZ8895_BMCR_COL_TEST                       0x0080
#define KSZ8895_BMCR_HP_MDIX                        0x0020
#define KSZ8895_BMCR_FORCE_MDI                      0x0010
#define KSZ8895_BMCR_AUTO_MDIX_DIS                  0x0008
#define KSZ8895_BMCR_FAR_END_FAULT_DIS              0x0004
#define KSZ8895_BMCR_TRANSMIT_DIS                   0x0002
#define KSZ8895_BMCR_LED_DIS                        0x0001

//MII Status register
#define KSZ8895_BMSR_100BT4                         0x8000
#define KSZ8895_BMSR_100BTX_FD                      0x4000
#define KSZ8895_BMSR_100BTX_HD                      0x2000
#define KSZ8895_BMSR_10BT_FD                        0x1000
#define KSZ8895_BMSR_10BT_HD                        0x0800
#define KSZ8895_BMSR_PREAMBLE_SUPPR                 0x0040
#define KSZ8895_BMSR_AN_COMPLETE                    0x0020
#define KSZ8895_BMSR_FAR_END_FAULT                  0x0010
#define KSZ8895_BMSR_AN_CAPABLE                     0x0008
#define KSZ8895_BMSR_LINK_STATUS                    0x0004
#define KSZ8895_BMSR_JABBER_TEST                    0x0002
#define KSZ8895_BMSR_EXTENDED_CAPABLE               0x0001

//PHYID High register
#define KSZ8895_PHYID1_DEFAULT                      0x0022

//PHYID Low register
#define KSZ8895_PHYID2_DEFAULT                      0x1450

//Advertisement Ability register
#define KSZ8895_ANAR_NEXT_PAGE                      0x8000
#define KSZ8895_ANAR_REMOTE_FAULT                   0x2000
#define KSZ8895_ANAR_PAUSE                          0x0400
#define KSZ8895_ANAR_100BTX_FD                      0x0100
#define KSZ8895_ANAR_100BTX_HD                      0x0080
#define KSZ8895_ANAR_10BT_FD                        0x0040
#define KSZ8895_ANAR_10BT_HD                        0x0020
#define KSZ8895_ANAR_SELECTOR                       0x001F
#define KSZ8895_ANAR_SELECTOR_DEFAULT               0x0001

//Link Partner Ability register
#define KSZ8895_ANLPAR_NEXT_PAGE                    0x8000
#define KSZ8895_ANLPAR_LP_ACK                       0x4000
#define KSZ8895_ANLPAR_REMOTE_FAULT                 0x2000
#define KSZ8895_ANLPAR_PAUSE                        0x0400
#define KSZ8895_ANLPAR_100BTX_FD                    0x0100
#define KSZ8895_ANLPAR_100BTX_HD                    0x0080
#define KSZ8895_ANLPAR_10BT_FD                      0x0040
#define KSZ8895_ANLPAR_10BT_HD                      0x0020

//LinkMD Control/Status register
#define KSZ8895_LINKMD_TEST_EN                      0x8000
#define KSZ8895_LINKMD_RESULT                       0x6000
#define KSZ8895_LINKMD_SHORT                        0x1000
#define KSZ8895_LINKMD_FAULT_COUNT                  0x01FF

//PHY Special Control/Status register
#define KSZ8895_PHYSCS_OP_MODE                      0x0700
#define KSZ8895_PHYSCS_OP_MODE_AN                   0x0100
#define KSZ8895_PHYSCS_OP_MODE_10BT_HD              0x0200
#define KSZ8895_PHYSCS_OP_MODE_100BTX_HD            0x0300
#define KSZ8895_PHYSCS_OP_MODE_10BT_FD              0x0500
#define KSZ8895_PHYSCS_OP_MODE_100BTX_FD            0x0600
#define KSZ8895_PHYSCS_OP_MODE_ISOLATE              0x0700
#define KSZ8895_PHYSCS_POLRVS                       0x0020
#define KSZ8895_PHYSCS_MDIX_STATUS                  0x0010
#define KSZ8895_PHYSCS_FORCE_LINK                   0x0008
#define KSZ8895_PHYSCS_PWRSAVE                      0x0004
#define KSZ8895_PHYSCS_REMOTE_LOOPBACK              0x0002

//Chip ID0 register
#define KSZ8895_CHIP_ID0_FAMILY_ID                  0xFF
#define KSZ8895_CHIP_ID0_FAMILY_ID_DEFAULT          0x95

//Chip ID1 / Start Switch register
#define KSZ8895_CHIP_ID1_CHIP_ID                    0xF0
#define KSZ8895_CHIP_ID1_CHIP_ID_MQX_FQX_MLX        0x40
#define KSZ8895_CHIP_ID1_CHIP_ID_RQX                0x60
#define KSZ8895_CHIP_ID1_REVISION_ID                0x0E
#define KSZ8895_CHIP_ID1_START_SWITCH               0x01

//Global Control 10 register
#define KSZ8895_GLOBAL_CTRL10_CLK_MODE              0x40
#define KSZ8895_GLOBAL_CTRL10_CPU_CLK_SEL           0x30
#define KSZ8895_GLOBAL_CTRL10_RESTORE_PREAMBLE_EN   0x04
#define KSZ8895_GLOBAL_CTRL10_TAIL_TAG_EN           0x02
#define KSZ8895_GLOBAL_CTRL10_PASS_FLOW_CTRL_PKT    0x01

//Port N Control 0 register
#define KSZ8895_PORTn_CTRL0_BCAST_STORM_PROTECT_EN  0x80
#define KSZ8895_PORTn_CTRL0_DIFFSERV_PRIO_CLASS_EN  0x40
#define KSZ8895_PORTn_CTRL0_802_1P_PRIO_CLASS_EN    0x20
#define KSZ8895_PORTn_CTRL0_PORT_PRIO_CLASS_EN      0x18
#define KSZ8895_PORTn_CTRL0_TAG_INSERTION           0x04
#define KSZ8895_PORTn_CTRL0_TAG_REMOVAL             0x02
#define KSZ8895_PORTn_CTRL0_TWO_QUEUE_SPLIT_EN      0x01

//Port N Control 1 register
#define KSZ8895_PORTn_CTRL1_SNIFFER_PORT            0x80
#define KSZ8895_PORTn_CTRL1_RECEIVE_SNIFF           0x40
#define KSZ8895_PORTn_CTRL1_TRANSMIT_SNIFF          0x20
#define KSZ8895_PORTn_CTRL1_PORT_VLAN_MEMBERSHIP    0x1F

//Port N Control 2 register
#define KSZ8895_PORTn_CTRL2_USER_PRIO_CEILING       0x80
#define KSZ8895_PORTn_CTRL2_INGRESS_VLAN_FILT       0x40
#define KSZ8895_PORTn_CTRL2_DISCARD_NON_PVID_PKT    0x20
#define KSZ8895_PORTn_CTRL2_FORCE_FLOW_CTRL         0x10
#define KSZ8895_PORTn_CTRL2_BACK_PRESSURE_EN        0x08
#define KSZ8895_PORTn_CTRL2_TRANSMIT_EN             0x04
#define KSZ8895_PORTn_CTRL2_RECEIVE_EN              0x02
#define KSZ8895_PORTn_CTRL2_LEARNING_DIS            0x01

//Port N Control 3 register
#define KSZ8895_PORTn_CTRL3_DEFAULT_USER_PRIO       0xE0
#define KSZ8895_PORTn_CTRL3_DEFAULT_CFI             0x10
#define KSZ8895_PORTn_CTRL3_DEFAULT_VID_MSB         0x0F

//Port N Control 4 register
#define KSZ8895_PORTn_CTRL4_DEFAULT_VID_LSB         0xFF

//RMII Management Control register
#define KSZ8895_RMII_MGMT_CTRL_SW5_CLK_OUT_DIS      0x08
#define KSZ8895_RMII_MGMT_CTRL_P5_CLK_OUT_DIS       0x04

//Port N Status 0 register
#define KSZ8895_PORTn_STAT0_HP_MDIX                 0x80
#define KSZ8895_PORTn_STAT0_POLRVS                  0x20
#define KSZ8895_PORTn_STAT0_TX_FLOW_CTRL_EN         0x10
#define KSZ8895_PORTn_STAT0_RX_FLOW_CTRL_EN         0x08
#define KSZ8895_PORTn_STAT0_OP_SPEED                0x04
#define KSZ8895_PORTn_STAT0_OP_DUPLEX               0x02

//Port N PHY Special Control/Status register
#define KSZ8895_PORTn_PSCS_VCT_10M_SHORT            0x80
#define KSZ8895_PORTn_PSCS_VCT_RESULT               0x60
#define KSZ8895_PORTn_PSCS_VCT_EN                   0x10
#define KSZ8895_PORTn_PSCS_FORCE_LNK                0x08
#define KSZ8895_PORTn_PSCS_PWRSAVE                  0x04
#define KSZ8895_PORTn_PSCS_REMOTE_LOOPBACK          0x02
#define KSZ8895_PORTn_PSCS_VCT_FAULT_COUNT_MSB      0x01

//Port N LinkMD Result register
#define KSZ8895_PORTn_LINKMD_VCT_FAULT_COUNT_LSB    0xFF

//Port N Status 1 register
#define KSZ8895_PORTn_STAT1_MDIX_STATUS             0x80
#define KSZ8895_PORTn_STAT1_AN_DONE                 0x40
#define KSZ8895_PORTn_STAT1_LINK_GOOD               0x20
#define KSZ8895_PORTn_STAT1_LP_FLOW_CTRL_CAPABLE    0x10
#define KSZ8895_PORTn_STAT1_LP_100BTX_FD_CAPABLE    0x08
#define KSZ8895_PORTn_STAT1_LP_100BTX_HF_CAPABLE    0x04
#define KSZ8895_PORTn_STAT1_LP_10BT_FD_CAPABLE      0x02
#define KSZ8895_PORTn_STAT1_LP_10BT_HD_CAPABLE      0x01

//Port N Control 7 / Status 2 register
#define KSZ8895_PORTn_CTRL7_STAT2_PHY_LOOPBACK      0x80
#define KSZ8895_PORTn_CTRL7_STAT2_PHY_ISOLATE       0x20
#define KSZ8895_PORTn_CTRL7_STAT2_SOFT_RESET        0x10
#define KSZ8895_PORTn_CTRL7_STAT2_FORCE_LINK        0x08
#define KSZ8895_PORTn_CTRL7_STAT2_OP_MODE           0x07
#define KSZ8895_PORTn_CTRL7_STAT2_OP_MODE_AN        0x01
#define KSZ8895_PORTn_CTRL7_STAT2_OP_MODE_10BT_HD   0x02
#define KSZ8895_PORTn_CTRL7_STAT2_OP_MODE_100BTX_HD 0x03
#define KSZ8895_PORTn_CTRL7_STAT2_OP_MODE_10BT_FD   0x05
#define KSZ8895_PORTn_CTRL7_STAT2_OP_MODE_100BTX_FD 0x06

//Identification register
#define KSZ8895_ID_REVISION_ID                      0xF0
#define KSZ8895_ID_REVISION_ID_MQX_RQX_FQX_REV_A2   0x40
#define KSZ8895_ID_REVISION_ID_ML_REV_B2            0x40
#define KSZ8895_ID_REVISION_ID_MQX_RQX_FQX_REV_A3   0x50
#define KSZ8895_ID_REVISION_ID_ML_REV_B3            0x50
#define KSZ8895_ID_REVISION_ID_MQX_RQX_FQX_REV_A4   0x60

//Tail tag encoding
#define KSZ8895_TAIL_TAG_ENCODE(port) (0x40 | (1 << (((port) - 1) & 0x03)))
//Tail tag decoding
#define KSZ8895_TAIL_TAG_DECODE(tag) (((tag) & 0x03) + 1)

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//KSZ8895 Ethernet switch driver
extern const PhyDriver ksz8895PhyDriver;

//KSZ8895 related functions
error_t ksz8895Init(NetInterface *interface);

bool_t ksz8895GetLinkState(NetInterface *interface, uint8_t port);

void ksz8895Tick(NetInterface *interface);

void ksz8895EnableIrq(NetInterface *interface);
void ksz8895DisableIrq(NetInterface *interface);

void ksz8895EventHandler(NetInterface *interface);

error_t ksz8895TagFrame(NetInterface *interface, NetBuffer *buffer,
   size_t *offset, uint8_t port, uint16_t *type);

error_t ksz8895UntagFrame(NetInterface *interface, uint8_t **frame,
   size_t *length, uint8_t *port);

void ksz8895WritePhyReg(NetInterface *interface, uint8_t port,
   uint8_t address, uint16_t data);

uint16_t ksz8895ReadPhyReg(NetInterface *interface, uint8_t port,
   uint8_t address);

void ksz8895DumpPhyReg(NetInterface *interface, uint8_t port);

void ksz8895WriteSwitchReg(NetInterface *interface, uint8_t address,
   uint8_t data);

uint8_t ksz8895ReadSwitchReg(NetInterface *interface, uint8_t address);

void ksz8895DumpSwitchReg(NetInterface *interface);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
