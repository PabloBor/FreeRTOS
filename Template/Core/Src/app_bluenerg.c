/*
 * app_bluenerg.c
 *
 *  Created on: Dec 20, 2023
 *      Author: levarela
 */
#include <stdio.h>
#include "bluenrg_conf.h"
#include "hci.h"
#include "bluenrg1_types.h"
#include "bluenrg1_gap.h"
#include "bluenrg1_aci.h"
#include "bluenrg1_hci_le.h"
#include "app_bluenerg.h"
#include "service.h"


#define BDADDR_SIZE    6

uint8_t SERVER_BDARR[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};

void bluenrg_init(void)
{

	tBleStatus ret;

	uint8_t bdaddr[BDADDR_SIZE];

	const char *name = "FirstBLE";

	// Create handlers for GAP service
	uint16_t service_handle, dev_name_char_handle, appearance_char_handle;


	BLUENRG_memcpy(bdaddr, SERVER_BDARR, sizeof(SERVER_BDARR));

	/*Initialize HCI*/
	hci_init(APP_UserEvrtRx,NULL);

	/*Reset HCI*/
	hci_reset();

	/*Wait 100 milliseconds*/
	HAL_Delay(100);

	/*Configure device address*/
	ret = aci_hal_write_config_data(CONFIG_DATA_PUBADDR_OFFSET, CONFIG_DATA_PUBADDR_LEN,bdaddr);
	if(ret != BLE_STATUS_SUCCESS)
	{
		printf("aci_hal_write_config_data : FAILED !! \n\r");
	}
	/*Initialize GATT server*/
	ret = aci_gatt_init();
	if( ret != BLE_STATUS_SUCCESS)
	{
		printf("aci_gatt_init : FAILED !! \n\r");
	}

	/*Initialize GAP server*/
	ret = aci_gap_init(GAP_PERIPHERAL_ROLE, 0, 0x07,&service_handle, &dev_name_char_handle, &appearance_char_handle);
	if( ret != BLE_STATUS_SUCCESS)
	{
		printf("aci_gap_init : FAILED !! \n\r");
	}

	/*Update characteristics*/
	ret = aci_gatt_update_char_value(service_handle, dev_name_char_handle, 0, strlen(name), (uint8_t*)name);
	if( ret != BLE_STATUS_SUCCESS)
	{
		printf("aci_gatt_update_char_value : FAILED !! \n\r");
	}

	/*Add custom service*/
	ret = add_simple_service();
	if( ret != BLE_STATUS_SUCCESS)
	{
		printf("add_simple_service : FAILED !! \n\r");
	}
}

void bluenrg_process(void)
{
	tBleStatus ret;

	uint8_t local_name[] = {AD_TYPE_COMPLETE_LOCAL_NAME, 'B', 'L', 'E', '-', 'K', 'E', 'Y', 'B','O','A','R','D'};

	/*Set device in General Discoverable mode*/
	ret = aci_gap_set_discoverable(ADV_IND, 0, 0, PUBLIC_ADDR, NO_WHITE_LIST_USE, sizeof(local_name), local_name, 0, NULL, 0, 0);

	if( ret != BLE_STATUS_SUCCESS)
	{
		printf("aci_gap_set_discoverable : FAILED !! \n\r");
	}

	/*Process user event*/
	hci_user_evt_proc();
}


