
# Pin assignments for Terasic ETH_DM9000 port add on attached to JP2
# http://www.doc88.com/p-7486217168335.html
#
#ENET_CMD		IO_B5	<------->	IO_B5	PIN_R12	JP2_GPIO_16    dm9000_cmd
#ENET_CS_n		IO_B2	<------->	IO_B2	PIN_T13	JP2_GPIO_13    dm9000_cs_n
#ENET_DATA[15]	IO_B13	<------->	IO_B13	PIN_L16	JP2_GPIO_116    dm9000_data[15]
#ENET_DATA[14]	IO_B14	<------->	IO_B14	PIN_K16	JP2_GPIO_117    dm9000_data[14]
#ENET_DATA[13]	IO_B11	<------->	IO_B11	PIN_N9	JP2_GPIO_114    dm9000_data[13]
#ENET_DATA[12]	IO_B12	<------->	IO_B12	PIN_N11	JP2_GPIO_115    dm9000_data[12]
#ENET_DATA[11]	IO_B9	<------->	IO_B9	PIN_N12	JP2_GPIO_112    dm9000_data[11]
#ENET_DATA[10]	IO_B10	<------->	IO_B10	PIN_P9	JP2_GPIO_113    dm9000_data[10]
#ENET_DATA[9]	IO_B7	<------->	IO_B7	PIN_P11	JP2_GPIO_110    dm9000_data[9]
#ENET_DATA[8]	IO_B8	<------->	IO_B8	PIN_R10	JP2_GPIO_111    dm9000_data[8]
#ENET_DATA[7]	IO_B22	<------->	IO_B22	PIN_P14	JP2_GPIO_125    dm9000_data[7]
#ENET_DATA[6]	IO_B21	<------->	IO_B21	PIN_N15	JP2_GPIO_124    dm9000_data[6]
#ENET_DATA[5]	IO_B20	<------->	IO_B20	PIN_N16	JP2_GPIO_123    dm9000_data[5]
#ENET_DATA[4]	IO_B19	<------->	IO_B19	PIN_R14	JP2_GPIO_122    dm9000_data[4]
#ENET_DATA[3]	IO_B18	<------->	IO_B18	PIN_P16	JP2_GPIO_121    dm9000_data[3]
#ENET_DATA[2]	IO_B17	<------->	IO_B17	PIN_P15	JP2_GPIO_120    dm9000_data[2]
#ENET_DATA[1]	IO_B16	<------->	IO_B16	PIN_L15	JP2_GPIO_119    dm9000_data[1]
#ENET_DATA[0]	IO_B15	<------->	IO_B15	PIN_R16	JP2_GPIO_118    dm9000_data[0]
#ENET_INT		IO_B6	<------->	IO_B6	PIN_T11	JP2_GPIO_17     dm9000_intr
#ENET_RD_n		IO_B3	<------->	IO_B3	PIN_R13	JP2_GPIO_14     dm9000_ior_n
#ENET_RST_n		IO_B1	<------->	IO_B1	PIN_T14	JP2_GPIO_12     dm9000_rst_n
#ENET_WR_n		IO_B4	<------->	IO_B4	PIN_T12	JP2_GPIO_15     dm9000_iow_n


set_location_assignment PIN_T13 -to dm9000_cs_n
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_cs_n
set_location_assignment PIN_R12 -to dm9000_cmd
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_cmd
set_location_assignment PIN_T11 -to dm9000_intr
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_intr
set_location_assignment PIN_R13 -to dm9000_ior_n
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_ior_n
set_location_assignment PIN_T14 -to dm9000_rst_n
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_rst_n
set_location_assignment PIN_T12 -to dm9000_iow_n
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_iow_n
set_location_assignment PIN_R16 -to dm9000_data[0]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[0]
set_location_assignment PIN_L15 -to dm9000_data[1]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[1]
set_location_assignment PIN_P15 -to dm9000_data[2]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[2]
set_location_assignment PIN_P16 -to dm9000_data[3]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[3]
set_location_assignment PIN_R14 -to dm9000_data[4]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[4]
set_location_assignment PIN_N16 -to dm9000_data[5]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[5]
set_location_assignment PIN_N15 -to dm9000_data[6]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[6]
set_location_assignment PIN_P14 -to dm9000_data[7]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[7]
set_location_assignment PIN_R10 -to dm9000_data[8]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[8]
set_location_assignment PIN_P11 -to dm9000_data[9]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[9]
set_location_assignment PIN_P9 -to dm9000_data[10]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[10]
set_location_assignment PIN_N12 -to dm9000_data[11]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[11]
set_location_assignment PIN_N11 -to dm9000_data[12]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[12]
set_location_assignment PIN_N9 -to dm9000_data[13]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[13]
set_location_assignment PIN_K16 -to dm9000_data[14]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[14]
set_location_assignment PIN_L16 -to dm9000_data[15]
set_instance_assignment -name IO_STANDARD "3.3-V LVTTL" -to dm9000_data[15]

