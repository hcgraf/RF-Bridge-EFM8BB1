/*
 * RF_Protocols.h
 *
 *  Created on: 28.11.2017
 *      Author:
 */

#ifndef INC_RF_PROTOCOLS_H_
#define INC_RF_PROTOCOLS_H_

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <stdint.h>
#include "RF_Config.h"

/*
 * bucket sniffing constants
 */
#define MIN_FOOTER_LENGTH	30
#define MIN_BUCKET_LENGTH	10

#define PT226x_SYNC_MIN		450

/*
 * sync constants
 */
#define TOLERANCE_MAX		50
#define TOLERANCE_MIN		10

/*
 * number of repeating by default
 */
#define RF_TRANSMIT_REPEATS		8

typedef struct PROTOCOL_STATUS
{
	uint16_t status;
	uint8_t bit_count;
	uint8_t actual_bit_of_byte;
} PROTOCOL_STATUS;

typedef struct PROTOCOL_DATA_UINT8_T
{
	// pointer to array of uint8_t elements
	SI_VARIABLE_SEGMENT_POINTER(dat, uint8_t, SI_SEG_CODE);
	// size of the array
	uint8_t size;
} PROTOCOL_DATA_UINT8_T;

typedef struct PROTOCOL_DATA_UINT16_T
{
	// pointer to array of uint16_t elements
	SI_VARIABLE_SEGMENT_POINTER(dat, uint16_t, SI_SEG_CODE);
	// size of the array
	uint8_t size;
} PROTOCOL_DATA_UINT16_T;

typedef struct BUCKET_PROTOCOL_DATA
{
	// array and array size of buckets
	PROTOCOL_DATA_UINT16_T buckets;
	// array and array size of start buckets
	PROTOCOL_DATA_UINT8_T start;
	// array and array size of bit 0 buckets
	PROTOCOL_DATA_UINT8_T bit0;
	// array and array size of bit 1 buckets
	PROTOCOL_DATA_UINT8_T bit1;
	// array and array size of end buckets
	PROTOCOL_DATA_UINT8_T end;
	// bit count for this protocol
	uint8_t bit_count;
} BUCKET_PROTOCOL_DATA;

/*
 * PT2260, EV1527,... original RF bridge protocol
 * http://www.princeton.com.tw/Portals/0/Product/PT2260_4.pdf
 */
#if EFM8BB1_SUPPORT_PT226X_PROTOCOL == 1
#define PT226X
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(PT226X)[], static uint16_t, SI_SEG_CODE) = { 35, 105, 1085 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(PT226X)[], static uint8_t, SI_SEG_CODE) = { HIGH(0), LOW(2) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(PT226X)[], static uint8_t, SI_SEG_CODE) = { HIGH(0), LOW(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(PT226X)[], static uint8_t, SI_SEG_CODE) = { HIGH(1), LOW(0) };
#endif

/*
 * Rohrmotor24
 * https://github.com/bjwelker/Raspi-Rollo/tree/master/Arduino/Rollo_Code_Receiver
 */
#if EFM8BB1_SUPPORT_Rohrmotor24_PROTOCOL == 1
#define Rohrmotor24
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(Rohrmotor24)[], static uint16_t, SI_SEG_CODE) = { 37, 74, 480, 150, 840 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(Rohrmotor24)[], static uint8_t, SI_SEG_CODE) = { HIGH(2), LOW(3) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(Rohrmotor24)[], static uint8_t, SI_SEG_CODE) = { HIGH(0), LOW(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(Rohrmotor24)[], static uint8_t, SI_SEG_CODE) = { HIGH(1), LOW(0) };
SI_SEGMENT_VARIABLE(PROTOCOL_END(Rohrmotor24)[], static uint8_t, SI_SEG_CODE) = { LOW(4) };
#endif

/*
 * UNDERWATER PAR56 LED LAMP, 502266
 * http://www.seamaid-lighting.com/de/produit/lampe-par56/
 */
#if EFM8BB1_SUPPORT_PAR56_PROTOCOL == 1
#define PAR56
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(PAR56)[], static uint16_t, SI_SEG_CODE) = { 38, 110, 300, 900 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(PAR56)[], static uint8_t, SI_SEG_CODE) = { HIGH(2), LOW(3) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(PAR56)[], static uint8_t, SI_SEG_CODE) = { HIGH(0), LOW(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(PAR56)[], static uint8_t, SI_SEG_CODE) = { HIGH(1), LOW(0) };
#endif

/*
 * Alecto WS-1200 Series Wireless Weather Station
 */
#if EFM8BB1_SUPPORT_WS_1200_PROTOCOL == 1
#define WS_1200
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(WS_1200)[], static uint16_t, SI_SEG_CODE) = { 50, 100, 150, 2950 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(WS_1200)[], static uint8_t, SI_SEG_CODE) = { LOW(3) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(WS_1200)[], static uint8_t, SI_SEG_CODE) = { HIGH(2), LOW(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(WS_1200)[], static uint8_t, SI_SEG_CODE) = { HIGH(0), LOW(1) };
#endif

/*
 * ALDI Remote controlled wall sockets, 4x
  */
#if EFM8BB1_SUPPORT_ALDI_4x_PROTOCOL == 1
#define ALDI_4x
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(ALDI_4x)[], static uint16_t, SI_SEG_CODE) = { 40, 120, 300, 725 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(ALDI_4x)[], static uint8_t, SI_SEG_CODE) = { HIGH(2), LOW(3) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(ALDI_4x)[], static uint8_t, SI_SEG_CODE) = { HIGH(0), LOW(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(ALDI_4x)[], static uint8_t, SI_SEG_CODE) = { HIGH(1), LOW(0) };
#endif

/*
 * HT6P20X chips
 * http://www.holtek.com.tw/documents/10179/11842/6p20v170.pdf
 */
#if EFM8BB1_SUPPORT_HT6P20X_PROTOCOL == 1
#define HT6P20X
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(HT6P20X)[], static uint16_t, SI_SEG_CODE) = { 45, 90, 1035 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(HT6P20X)[], static uint8_t, SI_SEG_CODE) = { LOW(2), HIGH(0) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(HT6P20X)[], static uint8_t, SI_SEG_CODE) = { LOW(0), HIGH(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(HT6P20X)[], static uint8_t, SI_SEG_CODE) = { LOW(1), HIGH(0) };
#endif

/*
 * HT12A/HT12E chips
 * http://www.holtek.com/documents/10179/116711/2_12ev120.pdf
 */
#if EFM8BB1_SUPPORT_HT12_PROTOCOL == 1
#define HT12
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(HT12)[], static uint16_t, SI_SEG_CODE) = { 21, 42, 756 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(HT12)[], static uint8_t, SI_SEG_CODE) = { LOW(2), HIGH(0) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(HT12)[], static uint8_t, SI_SEG_CODE) = { LOW(0), HIGH(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(HT12)[], static uint8_t, SI_SEG_CODE) = { LOW(1), HIGH(0) };
#endif

/*
 * HT12A/HT12E chips - Generic Doorbell
 * http://www.holtek.com/documents/10179/116711/2_12ev120.pdf
 */
#if EFM8BB1_SUPPORT_HT12a_PROTOCOL == 1
#define HT12a
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(HT12a)[], static uint16_t, SI_SEG_CODE) = { 20, 38, 695 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(HT12a)[], static uint8_t, SI_SEG_CODE) = { LOW(2), HIGH(0) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(HT12a)[], static uint8_t, SI_SEG_CODE) = { LOW(0), HIGH(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(HT12a)[], static uint8_t, SI_SEG_CODE) = { LOW(1), HIGH(0) };
#endif

/*
 * HT12A/HT12E chips - Atag Extractor - Plus/Minus
 * http://www.holtek.com/documents/10179/116711/2_12ev120.pdf
 */
#if EFM8BB1_SUPPORT_HT12_Atag_PROTOCOL == 1
#define HT12b
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(HT12b)[], static uint16_t, SI_SEG_CODE) = { 35, 65, 1300 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(HT12b)[], static uint8_t, SI_SEG_CODE) = { LOW(2), HIGH(0) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(HT12b)[], static uint8_t, SI_SEG_CODE) = { LOW(0), HIGH(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(HT12b)[], static uint8_t, SI_SEG_CODE) = { LOW(1), HIGH(0) };
#endif

/*
 * HT12A/HT12E chips - Atag Extractor - Lights/Timer
 * http://www.holtek.com/documents/10179/116711/2_12ev120.pdf
 */
#if EFM8BB1_SUPPORT_HT12_Atag_PROTOCOL == 1
#define HT12c
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(HT12c)[], static uint16_t, SI_SEG_CODE) = { 35, 70, 1565 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(HT12c)[], static uint8_t, SI_SEG_CODE) = { LOW(2), HIGH(0) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(HT12c)[], static uint8_t, SI_SEG_CODE) = { LOW(0), HIGH(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(HT12c)[], static uint8_t, SI_SEG_CODE) = { LOW(1), HIGH(0) };
#endif

/*
 * Meteo SPxx -  Weather station (PHU Metrex)
 * https://gist.github.com/klaper/ce3ba02501516d9a6d294367d2c300a6
 */
#if EFM8BB1_SUPPORT_SP45_PROTOCOL == 1
#define SP45
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(SP45)[], static uint16_t, SI_SEG_CODE) = { 65, 781, 182, 398 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(SP45)[], static uint8_t, SI_SEG_CODE) = { HIGH(0), LOW(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(SP45)[], static uint8_t, SI_SEG_CODE) = { HIGH(0), LOW(2) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(SP45)[], static uint8_t, SI_SEG_CODE) = { HIGH(0), LOW(3) };
#endif

/*
 * Dooya DC90 remote
 */
#if EFM8BB1_SUPPORT_DC90_PROTOCOL == 1
#define DC90
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(DC90)[], static uint16_t, SI_SEG_CODE) = { 36, 72, 480, 150 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(DC90)[], static uint8_t, SI_SEG_CODE) = { HIGH(2), LOW(3) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(DC90)[], static uint8_t, SI_SEG_CODE) = { HIGH(0), LOW(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(DC90)[], static uint8_t, SI_SEG_CODE) = { HIGH(1), LOW(0) };
#endif

/*
 * Digoo DG-HOSA Smart 433MHz Wireless Household Carbon Monoxide Sensor
 */
#if EFM8BB1_SUPPORT_DG_HOSA_PROTOCOL == 1
#define DG_HOSA
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(DG_HOSA)[], static uint16_t, SI_SEG_CODE) = { 59, 150, 43, 1345 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(DG_HOSA)[], static uint8_t, SI_SEG_CODE) = { HIGH(2), LOW(3) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(DG_HOSA)[], static uint8_t, SI_SEG_CODE) = { HIGH(0), LOW(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(DG_HOSA)[], static uint8_t, SI_SEG_CODE) = { HIGH(1), LOW(0) };
#endif

/*
 * KaKu wall sockets
 */
#if EFM8BB1_SUPPORT_Kaku_PROTOCOL == 1
#define KaKu
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(KaKu)[], static uint16_t, SI_SEG_CODE) = { 30, 256, 14, 115, 1023 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(KaKu)[], static uint8_t, SI_SEG_CODE) = {  HIGH(0), LOW(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(KaKu)[], static uint8_t, SI_SEG_CODE) = {  HIGH(0), LOW(3),  HIGH(0), LOW(2) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(KaKu)[], static uint8_t, SI_SEG_CODE) = {  HIGH(0), LOW(2),  HIGH(0), LOW(3) };
SI_SEGMENT_VARIABLE(PROTOCOL_END(KaKu)[], static uint8_t, SI_SEG_CODE) = {  HIGH(0), LOW(4) };
#endif

/*
 * Quigg GT-7000
 * https://manual.pilight.org/protocols/433.92/switch/quigg_7000.html
 */
#if EFM8BB1_SUPPORT_Quigg_PROTOCOL == 1
#define Quigg
SI_SEGMENT_VARIABLE(PROTOCOL_BUCKETS(Quigg)[], static uint16_t, SI_SEG_CODE) = { 70, 140, 8100 };
SI_SEGMENT_VARIABLE(PROTOCOL_START(Quigg)[], static uint8_t, SI_SEG_CODE) = {  LOW(2), HIGH(0) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT0(Quigg)[], static uint8_t, SI_SEG_CODE) = {  LOW(0), HIGH(1) };
SI_SEGMENT_VARIABLE(PROTOCOL_BIT1(Quigg)[], static uint8_t, SI_SEG_CODE) = {  LOW(1), HIGH(0) };
#endif

SI_SEGMENT_VARIABLE(PROTOCOL_DATA[], static struct BUCKET_PROTOCOL_DATA, SI_SEG_CODE) =
{
#if EFM8BB1_SUPPORT_PT226X_PROTOCOL == 1
		/*
		 * PT2260, EV1527,... original RF bridge protocol
		 */
		{
			{ &PROTOCOL_BUCKETS(PT226X), ARRAY_LENGTH(PROTOCOL_BUCKETS(PT226X)) },
			{ &PROTOCOL_START(PT226X), ARRAY_LENGTH(PROTOCOL_START(PT226X)) },
			{ &PROTOCOL_BIT0(PT226X), ARRAY_LENGTH(PROTOCOL_BIT0(PT226X)) },
			{ &PROTOCOL_BIT1(PT226X), ARRAY_LENGTH(PROTOCOL_BIT1(PT226X)) },
			{ NULL, 0 },
			24
		},
#endif
#if EFM8BB1_SUPPORT_Rohrmotor24_PROTOCOL == 1
		/*
		 * Rohrmotor24
		 */
		{
			{ &PROTOCOL_BUCKETS(Rohrmotor24), ARRAY_LENGTH(PROTOCOL_BUCKETS(Rohrmotor24)) },
			{ &PROTOCOL_START(Rohrmotor24), ARRAY_LENGTH(PROTOCOL_START(Rohrmotor24)) },
			{ &PROTOCOL_BIT0(Rohrmotor24), ARRAY_LENGTH(PROTOCOL_BIT0(Rohrmotor24)) },
			{ &PROTOCOL_BIT1(Rohrmotor24), ARRAY_LENGTH(PROTOCOL_BIT1(Rohrmotor24)) },
			{ &PROTOCOL_END(Rohrmotor24), ARRAY_LENGTH(PROTOCOL_END(Rohrmotor24)) },
			40
		},
#endif
#if EFM8BB1_SUPPORT_PAR56_PROTOCOL == 1
		/*
		 * UNDERWATER PAR56 LED LAMP, 502266
		 */
		{
			{ &PROTOCOL_BUCKETS(PAR56), ARRAY_LENGTH(PROTOCOL_BUCKETS(PAR56)) },
			{ &PROTOCOL_START(PAR56), ARRAY_LENGTH(PROTOCOL_START(PAR56)) },
			{ &PROTOCOL_BIT0(PAR56), ARRAY_LENGTH(PROTOCOL_BIT0(PAR56)) },
			{ &PROTOCOL_BIT1(PAR56), ARRAY_LENGTH(PROTOCOL_BIT1(PAR56)) },
			{ NULL, 0 },
			24
		},
#endif
#if EFM8BB1_SUPPORT_WS_1200_PROTOCOL == 1
		/*
		 * Alecto WS-1200 Series Wireless Weather Station
		 */
		{
			{ &PROTOCOL_BUCKETS(WS_1200), ARRAY_LENGTH(PROTOCOL_BUCKETS(WS_1200)) },
			{ &PROTOCOL_START(WS_1200), ARRAY_LENGTH(PROTOCOL_START(WS_1200)) },
			{ &PROTOCOL_BIT0(WS_1200), ARRAY_LENGTH(PROTOCOL_BIT0(WS_1200)) },
			{ &PROTOCOL_BIT1(WS_1200), ARRAY_LENGTH(PROTOCOL_BIT1(WS_1200)) },
			{ NULL, 0 },
			71
		},
#endif
#if EFM8BB1_SUPPORT_ALDI_4x_PROTOCOL == 1
		/*
		 * ALDI Remote controlled wall sockets, 4x
		 */
		{
			{ &PROTOCOL_BUCKETS(ALDI_4x), ARRAY_LENGTH(PROTOCOL_BUCKETS(ALDI_4x)) },
			{ &PROTOCOL_START(ALDI_4x), ARRAY_LENGTH(PROTOCOL_START(ALDI_4x)) },
			{ &PROTOCOL_BIT0(ALDI_4x), ARRAY_LENGTH(PROTOCOL_BIT0(ALDI_4x)) },
			{ &PROTOCOL_BIT1(ALDI_4x), ARRAY_LENGTH(PROTOCOL_BIT1(ALDI_4x)) },
			{ NULL, 0 },
			24
		},
#endif
#if EFM8BB1_SUPPORT_HT6P20X_PROTOCOL == 1
		/*
		 * HT6P20X chips
		 */
		{
			{ &PROTOCOL_BUCKETS(HT6P20X), ARRAY_LENGTH(PROTOCOL_BUCKETS(HT6P20X)) },
			{ &PROTOCOL_START(HT6P20X), ARRAY_LENGTH(PROTOCOL_START(HT6P20X)) },
			{ &PROTOCOL_BIT0(HT6P20X), ARRAY_LENGTH(PROTOCOL_BIT0(HT6P20X)) },
			{ &PROTOCOL_BIT1(HT6P20X), ARRAY_LENGTH(PROTOCOL_BIT1(HT6P20X)) },
			{ NULL, 0 },
			24
		},
#endif
#if EFM8BB1_SUPPORT_HT12_PROTOCOL == 1
		/*
		 * HT12A/HT12E chips
		 */
		{
			{ &PROTOCOL_BUCKETS(HT12), ARRAY_LENGTH(PROTOCOL_BUCKETS(HT12)) },
			{ &PROTOCOL_START(HT12), ARRAY_LENGTH(PROTOCOL_START(HT12)) },
			{ &PROTOCOL_BIT0(HT12), ARRAY_LENGTH(PROTOCOL_BIT0(HT12)) },
			{ &PROTOCOL_BIT1(HT12), ARRAY_LENGTH(PROTOCOL_BIT1(HT12)) },
			{ NULL, 0 },
			12
		},
#endif
#if EFM8BB1_SUPPORT_HT12a_PROTOCOL == 1
		/*
		 * HT12A/HT12E chips - A
		 */
		{
			{ &PROTOCOL_BUCKETS(HT12a), ARRAY_LENGTH(PROTOCOL_BUCKETS(HT12a)) },
			{ &PROTOCOL_START(HT12a), ARRAY_LENGTH(PROTOCOL_START(HT12a)) },
			{ &PROTOCOL_BIT0(HT12a), ARRAY_LENGTH(PROTOCOL_BIT0(HT12a)) },
			{ &PROTOCOL_BIT1(HT12a), ARRAY_LENGTH(PROTOCOL_BIT1(HT12a)) },
			{ NULL, 0 },
			12
		},
#endif
#if EFM8BB1_SUPPORT_HT12_Atag_PROTOCOL == 1
		/*
		 * HT12A/HT12E chips - B
		 */
		{
			{ &PROTOCOL_BUCKETS(HT12b), ARRAY_LENGTH(PROTOCOL_BUCKETS(HT12b)) },
			{ &PROTOCOL_START(HT12b), ARRAY_LENGTH(PROTOCOL_START(HT12b)) },
			{ &PROTOCOL_BIT0(HT12b), ARRAY_LENGTH(PROTOCOL_BIT0(HT12b)) },
			{ &PROTOCOL_BIT1(HT12b), ARRAY_LENGTH(PROTOCOL_BIT1(HT12b)) },
			{ NULL, 0 },
			12
		},
#endif
#if EFM8BB1_SUPPORT_HT12_Atag_PROTOCOL == 1
		/*
		 * HT12A/HT12E chips - C
		 */
		{
			{ &PROTOCOL_BUCKETS(HT12c), ARRAY_LENGTH(PROTOCOL_BUCKETS(HT12c)) },
			{ &PROTOCOL_START(HT12c), ARRAY_LENGTH(PROTOCOL_START(HT12c)) },
			{ &PROTOCOL_BIT0(HT12c), ARRAY_LENGTH(PROTOCOL_BIT0(HT12c)) },
			{ &PROTOCOL_BIT1(HT12c), ARRAY_LENGTH(PROTOCOL_BIT1(HT12c)) },
			{ NULL, 0 },
			18
		},
#endif
#if EFM8BB1_SUPPORT_SP45_PROTOCOL == 1
		/*
		 * Meteo SPxx -  Weather station (PHU Metrex)
		 */
		{
			{ &PROTOCOL_BUCKETS(SP45), ARRAY_LENGTH(PROTOCOL_BUCKETS(SP45)) },
			{ &PROTOCOL_START(SP45), ARRAY_LENGTH(PROTOCOL_START(SP45)) },
			{ &PROTOCOL_BIT0(SP45), ARRAY_LENGTH(PROTOCOL_BIT0(SP45)) },
			{ &PROTOCOL_BIT1(SP45), ARRAY_LENGTH(PROTOCOL_BIT1(SP45)) },
			{ NULL, 0 },
			40
		},
#endif
#if EFM8BB1_SUPPORT_DC90_PROTOCOL == 1
		/*
		 * Dooya DC90 remote
		 */
		{
			{ &PROTOCOL_BUCKETS(DC90), ARRAY_LENGTH(PROTOCOL_BUCKETS(DC90)) },
			{ &PROTOCOL_START(DC90), ARRAY_LENGTH(PROTOCOL_START(DC90)) },
			{ &PROTOCOL_BIT0(DC90), ARRAY_LENGTH(PROTOCOL_BIT0(DC90)) },
			{ &PROTOCOL_BIT1(DC90), ARRAY_LENGTH(PROTOCOL_BIT1(DC90)) },
			{ NULL, 0 },
			40
		},
#endif
#if EFM8BB1_SUPPORT_DG_HOSA_PROTOCOL == 1
		/*
		 * Digoo DG-HOSA Smart 433MHz Wireless Household Carbon Monoxide Sensor
		 */
		{
			{ &PROTOCOL_BUCKETS(DG_HOSA), ARRAY_LENGTH(PROTOCOL_BUCKETS(DG_HOSA)) },
			{ &PROTOCOL_START(DG_HOSA), ARRAY_LENGTH(PROTOCOL_START(DG_HOSA)) },
			{ &PROTOCOL_BIT0(DG_HOSA), ARRAY_LENGTH(PROTOCOL_BIT0(DG_HOSA)) },
			{ &PROTOCOL_BIT1(DG_HOSA), ARRAY_LENGTH(PROTOCOL_BIT1(DG_HOSA)) },
			{ NULL, 0 },
			24
		},
#endif
#if EFM8BB1_SUPPORT_Kaku_PROTOCOL == 1
		/*
		 * KaKu wall sockets
		 */
		{
			{ &PROTOCOL_BUCKETS(KaKu), ARRAY_LENGTH(PROTOCOL_BUCKETS(KaKu)) },
			{ &PROTOCOL_START(KaKu), ARRAY_LENGTH(PROTOCOL_START(KaKu)) },
			{ &PROTOCOL_BIT0(KaKu), ARRAY_LENGTH(PROTOCOL_BIT0(KaKu)) },
			{ &PROTOCOL_BIT1(KaKu), ARRAY_LENGTH(PROTOCOL_BIT1(KaKu)) },
			{ &PROTOCOL_END(KaKu), ARRAY_LENGTH(PROTOCOL_END(KaKu)) },
			32
		},
#endif
#if EFM8BB1_SUPPORT_Quigg_PROTOCOL == 1
		/*
		 * Quigg GT-7000
		 */
		{
			{ &PROTOCOL_BUCKETS(Quigg), ARRAY_LENGTH(PROTOCOL_BUCKETS(Quigg)) },
			{ &PROTOCOL_START(Quigg), ARRAY_LENGTH(PROTOCOL_START(Quigg)) },
			{ &PROTOCOL_BIT0(Quigg), ARRAY_LENGTH(PROTOCOL_BIT0(Quigg)) },
			{ &PROTOCOL_BIT1(Quigg), ARRAY_LENGTH(PROTOCOL_BIT1(Quigg)) },
			{ NULL, 0 },
			20
		},
#endif
};

#define PROTOCOLCOUNT (sizeof(PROTOCOL_DATA) / sizeof(PROTOCOL_DATA[0]))
#endif /* INC_RF_PROTOCOLS_H_ */
