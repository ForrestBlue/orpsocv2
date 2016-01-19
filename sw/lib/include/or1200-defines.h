//This file is autogenerated from ../../../rtl/verilog/include/or1200_defines.v do not change!
#ifndef _OR1200_DEFINES_H_
#define _OR1200_DEFINES_H_































































#ifdef OR1200_ASIC







#define OR1200_VIRTUALSILICON_SSP



























#define OR1200_GENERIC_MULTP2_32X32






#define OR1200_IC_1W_8KB

#define OR1200_DC_1W_8KB

#else










#define OR1200_ALTERA_LPM


































#define OR1200_GENERIC_MULTP2_32X32






#define OR1200_IC_1W_4KB



#define OR1200_DC_1W_4KB




#endif


























#define OR1200_REGISTERED_OUTPUTS

















































#define OR1200_WB_B3




#define OR1200_LOG_WB_ACCESS














#define OR1200_CASE_DEFAULT






#define OR1200_OPERAND_WIDTH		32
#define OR1200_REGFILE_ADDR_WIDTH	5























#define OR1200_IMPL_ADDC









#define OR1200_IMPL_SUB











#define OR1200_IMPL_CY







#define OR1200_IMPL_OV







#define OR1200_IMPL_OVE


























#define OR1200_IMPL_ALU_COMP3




#define OR1200_IMPL_ALU_FFL1









#define OR1200_IMPL_ALU_EXT






#define OR1200_MULT_IMPLEMENTED








#define OR1200_MAC_IMPLEMENTED








#define OR1200_DIV_IMPLEMENTED











#define OR1200_DIV_SERIAL




#define OR1200_FPU_IMPLEMENTED























#define OR1200_RFRAM_DUALPORT





#ifdef OR1200_RFRAM_GENERIC

#endif








#define OR1200_IMPL_MEM2REG1





#ifdef OR1200_RST_ACT_LOW
  #define OR1200_RST_EVENT      negedge
#else
  #define OR1200_RST_EVENT      posedge
#endif




#define OR1200_ALUOP_WIDTH	5
/* LS-nibble encodings correspond to bits [3:0] of instruction */

/* Values sent to ALU from decode unit - not defined by ISA */


#define OR1200_ALUOP2_POS	9:6
#define OR1200_ALUOP2_WIDTH	4




#define OR1200_MACOP_WIDTH	3




#define OR1200_SHROTOP_WIDTH	4




#define OR1200_EXTHBOP_WIDTH      4
#define OR1200_EXTWOP_WIDTH       4


#define OR1200_MULTICYCLE_WIDTH	3


#define OR1200_WAIT_ON_WIDTH 2



#define OR1200_SEL_WIDTH		2




#define OR1200_BRANCHOP_WIDTH		3







#define OR1200_LSUOP_WIDTH		4





#define OR1200_LSUEA_PRECALC		2


#define OR1200_FETCHOP_WIDTH		1







#define OR1200_RFWBOP_WIDTH		4


#define OR1200_COMPOP_WIDTH	4






#define OR1200_FPUOP_WIDTH	8



#define OR1200_FPUOP_DOUBLE_BIT 4

















#define OR1200_SHROTOP_POS		7:6




/* */
/* */
/* */
/* */
































#define OR1200_EXCEPT_WIDTH 4















#define OR1200_SPR_GROUP_BITS	15:11


#define OR1200_SPR_GROUP_WIDTH 	5


#define OR1200_SPR_OFS_BITS 10:0















#define OR1200_SR_WIDTH 17
#define OR1200_SR_SM   0
#define OR1200_SR_TEE  1
#define OR1200_SR_IEE  2
#define OR1200_SR_DCE  3
#define OR1200_SR_ICE  4
#define OR1200_SR_DME  5
#define OR1200_SR_IME  6
#define OR1200_SR_LEE  7
#define OR1200_SR_CE   8
#define OR1200_SR_F    9
#define OR1200_SR_CY   10	
#define OR1200_SR_OV   11	
#define OR1200_SR_OVE  12	
#define OR1200_SR_DSX  13	
#define OR1200_SR_EPH  14
#define OR1200_SR_FO   15
#define OR1200_SR_TED  16
#define OR1200_SR_CID  31:28	




#define OR1200_SPROFS_BITS 10:0












#define OR1200_FPCSR_WIDTH 12
#define OR1200_FPCSR_FPEE  0
#define OR1200_FPCSR_RM    2:1
#define OR1200_FPCSR_OVF   3
#define OR1200_FPCSR_UNF   4
#define OR1200_FPCSR_SNF   5
#define OR1200_FPCSR_QNF   6
#define OR1200_FPCSR_ZF    7
#define OR1200_FPCSR_IXF   8
#define OR1200_FPCSR_IVF   9
#define OR1200_FPCSR_INF   10
#define OR1200_FPCSR_DZF   11
#define OR1200_FPCSR_RES   31:12










#define OR1200_PM_PMR_SDF 3:0
#define OR1200_PM_PMR_DME 4
#define OR1200_PM_PMR_SME 5
#define OR1200_PM_PMR_DCGE 6
#define OR1200_PM_PMR_UNUSED 31:7






#define OR1200_PM_PARTIAL_DECODING


#define OR1200_PM_READREGS


#define OR1200_PM_UNUSED_ZERO








#define OR1200_DU_IMPLEMENTED














#define OR1200_DU_DVRDCR_PAIRS 8











#ifdef OR1200_DU_HWBKPTS
#endif
#ifdef OR1200_DU_HWBKPTS
#endif
#ifdef OR1200_DU_TB_IMPLEMENTED
#endif


#define OR1200_DUOFS_BITS	10:0


#define OR1200_DU_DCR_DP	0
#define OR1200_DU_DCR_CC	3:1
#define OR1200_DU_DCR_SC	4
#define OR1200_DU_DCR_CT	7:5


#define OR1200_DU_DMR1_CW0	1:0
#define OR1200_DU_DMR1_CW1	3:2
#define OR1200_DU_DMR1_CW2	5:4
#define OR1200_DU_DMR1_CW3	7:6
#define OR1200_DU_DMR1_CW4	9:8
#define OR1200_DU_DMR1_CW5	11:10
#define OR1200_DU_DMR1_CW6	13:12
#define OR1200_DU_DMR1_CW7	15:14
#define OR1200_DU_DMR1_CW8	17:16
#define OR1200_DU_DMR1_CW9	19:18
#define OR1200_DU_DMR1_CW10	21:20
#define OR1200_DU_DMR1_ST	22
#define OR1200_DU_DMR1_BT	23
#define OR1200_DU_DMR1_DXFW	24
#define OR1200_DU_DMR1_ETE	25


#define OR1200_DU_DMR2_WCE0	0
#define OR1200_DU_DMR2_WCE1	1
#define OR1200_DU_DMR2_AWTC	12:2
#define OR1200_DU_DMR2_WGB	23:13


#define OR1200_DU_DWCR_COUNT	15:0
#define OR1200_DU_DWCR_MATCH	31:16


#define OR1200_DU_DSR_WIDTH	14
#define OR1200_DU_DSR_RSTE	0
#define OR1200_DU_DSR_BUSEE	1
#define OR1200_DU_DSR_DPFE	2
#define OR1200_DU_DSR_IPFE	3
#define OR1200_DU_DSR_TTE	4
#define OR1200_DU_DSR_AE	5
#define OR1200_DU_DSR_IIE	6
#define OR1200_DU_DSR_IE	7
#define OR1200_DU_DSR_DME	8
#define OR1200_DU_DSR_IME	9
#define OR1200_DU_DSR_RE	10
#define OR1200_DU_DSR_SCE	11
#define OR1200_DU_DSR_FPE	12
#define OR1200_DU_DSR_TE	13


#define OR1200_DU_DRR_RSTE	0
#define OR1200_DU_DRR_BUSEE	1
#define OR1200_DU_DRR_DPFE	2
#define OR1200_DU_DRR_IPFE	3
#define OR1200_DU_DRR_TTE	4
#define OR1200_DU_DRR_AE	5
#define OR1200_DU_DRR_IIE	6
#define OR1200_DU_DRR_IE	7
#define OR1200_DU_DRR_DME	8
#define OR1200_DU_DRR_IME	9
#define OR1200_DU_DRR_RE	10
#define OR1200_DU_DRR_SCE	11
#define OR1200_DU_DRR_FPE	12
#define OR1200_DU_DRR_TE	13


#define OR1200_DU_READREGS


#define OR1200_DU_UNUSED_ZERO


#define OR1200_DU_STATUS_UNIMPLEMENTED







#define OR1200_PIC_IMPLEMENTED


#define OR1200_PIC_INTS 20




#define OR1200_PICOFS_BITS 1:0


#define OR1200_PIC_PICMR
#define OR1200_PIC_PICSR


#define OR1200_PIC_READREGS


#define OR1200_PIC_UNUSED_ZERO








#define OR1200_TT_IMPLEMENTED




#define OR1200_TTOFS_BITS 0


#define OR1200_TT_TTMR
#define OR1200_TT_TTCR


#define OR1200_TT_TTMR_TP 27:0
#define OR1200_TT_TTMR_IP 28
#define OR1200_TT_TTMR_IE 29
#define OR1200_TT_TTMR_M 31:30


#define OR1200_TT_READREGS






#define OR1200_MAC_ADDR		0	
#define OR1200_MAC_SPR_WE		











#define OR1200_MAC_SHIFTBY	0	










#define OR1200_DTLB_TM_ADDR	7




#define	OR1200_DTLBMR_V_BITS	0
#define	OR1200_DTLBMR_CID_BITS	4:1
#define	OR1200_DTLBMR_RES_BITS	11:5
#define OR1200_DTLBMR_VPN_BITS	31:13




#define	OR1200_DTLBTR_CC_BITS	0
#define	OR1200_DTLBTR_CI_BITS	1
#define	OR1200_DTLBTR_WBC_BITS	2
#define	OR1200_DTLBTR_WOM_BITS	3
#define	OR1200_DTLBTR_A_BITS	4
#define	OR1200_DTLBTR_D_BITS	5
#define	OR1200_DTLBTR_URE_BITS	6
#define	OR1200_DTLBTR_UWE_BITS	7
#define	OR1200_DTLBTR_SRE_BITS	8
#define	OR1200_DTLBTR_SWE_BITS	9
#define	OR1200_DTLBTR_RES_BITS	11:10
#define OR1200_DTLBTR_PPN_BITS	31:13




#define	OR1200_DMMU_PS		13					
#define	OR1200_DTLB_INDXW	6					
#define OR1200_DTLB_INDXL	#OR1200_DMMU_PS				
#define OR1200_DTLB_INDXH	#OR1200_DMMU_PS+#OR1200_DTLB_INDXW-1	
#define	OR1200_DTLB_INDX	#OR1200_DTLB_INDXH:#OR1200_DTLB_INDXL	
#define OR1200_DTLB_TAGW	32-#OR1200_DTLB_INDXW-#OR1200_DMMU_PS	
#define OR1200_DTLB_TAGL	#OR1200_DTLB_INDXH+1			
#define	OR1200_DTLB_TAG		31:#OR1200_DTLB_TAGL			
#define	OR1200_DTLBMRW		#OR1200_DTLB_TAGW+1			
#define	OR1200_DTLBTRW		32-#OR1200_DMMU_PS+5			











#define OR1200_DMMU_CI			dcpu_adr_i[31]










#define OR1200_ITLB_TM_ADDR	7




#define	OR1200_ITLBMR_V_BITS	0
#define	OR1200_ITLBMR_CID_BITS	4:1
#define	OR1200_ITLBMR_RES_BITS	11:5
#define OR1200_ITLBMR_VPN_BITS	31:13




#define	OR1200_ITLBTR_CC_BITS	0
#define	OR1200_ITLBTR_CI_BITS	1
#define	OR1200_ITLBTR_WBC_BITS	2
#define	OR1200_ITLBTR_WOM_BITS	3
#define	OR1200_ITLBTR_A_BITS	4
#define	OR1200_ITLBTR_D_BITS	5
#define	OR1200_ITLBTR_SXE_BITS	6
#define	OR1200_ITLBTR_UXE_BITS	7
#define	OR1200_ITLBTR_RES_BITS	11:8
#define OR1200_ITLBTR_PPN_BITS	31:13




#define	OR1200_IMMU_PS		13					
#define	OR1200_ITLB_INDXW	6					
#define OR1200_ITLB_INDXL	#OR1200_IMMU_PS				
#define OR1200_ITLB_INDXH	#OR1200_IMMU_PS+#OR1200_ITLB_INDXW-1	
#define	OR1200_ITLB_INDX	#OR1200_ITLB_INDXH:#OR1200_ITLB_INDXL	
#define OR1200_ITLB_TAGW	32-#OR1200_ITLB_INDXW-#OR1200_IMMU_PS	
#define OR1200_ITLB_TAGL	#OR1200_ITLB_INDXH+1			
#define	OR1200_ITLB_TAG		31:#OR1200_ITLB_TAGL			
#define	OR1200_ITLBMRW		#OR1200_ITLB_TAGW+1			
#define	OR1200_ITLBTRW		32-#OR1200_IMMU_PS+3			




















#ifdef OR1200_IC_1W_32KB
 #define OR1200_ICLS		5
#else
 #define OR1200_ICLS		4
#endif




#ifdef OR1200_IC_1W_512B
#define OR1200_ICSIZE                   9                       
#define OR1200_ICINDX                   #OR1200_ICSIZE-2        
#define OR1200_ICINDXH                  #OR1200_ICSIZE-1        
#define OR1200_ICTAGL                   #OR1200_ICINDXH+1       
#define OR1200_ICTAG                    #OR1200_ICSIZE-#OR1200_ICLS 
#define OR1200_ICTAG_W                  24
#endif
#ifdef OR1200_IC_1W_4KB
#define OR1200_ICSIZE			12			
#define OR1200_ICINDX			#OR1200_ICSIZE-2	
#define OR1200_ICINDXH			#OR1200_ICSIZE-1	
#define OR1200_ICTAGL			#OR1200_ICINDXH+1	
#define	OR1200_ICTAG			#OR1200_ICSIZE-#OR1200_ICLS	
#define	OR1200_ICTAG_W			21
#endif
#ifdef OR1200_IC_1W_8KB
#define OR1200_ICSIZE			13			
#define OR1200_ICINDX			#OR1200_ICSIZE-2	
#define OR1200_ICINDXH			#OR1200_ICSIZE-1	
#define OR1200_ICTAGL			#OR1200_ICINDXH+1	
#define	OR1200_ICTAG			#OR1200_ICSIZE-#OR1200_ICLS	
#define	OR1200_ICTAG_W			20
#endif
#ifdef OR1200_IC_1W_16KB
#define OR1200_ICSIZE			14			
#define OR1200_ICINDX			#OR1200_ICSIZE-2	
#define OR1200_ICINDXH			#OR1200_ICSIZE-1	
#define OR1200_ICTAGL			#OR1200_ICINDXH+1	
#define	OR1200_ICTAG			#OR1200_ICSIZE-#OR1200_ICLS	
#define	OR1200_ICTAG_W			19
#endif
#ifdef OR1200_IC_1W_32KB
#define OR1200_ICSIZE			15			
#define OR1200_ICINDX			#OR1200_ICSIZE-2	
#define OR1200_ICINDXH			#OR1200_ICSIZE-1	
#define OR1200_ICTAGL			#OR1200_ICINDXH+1	
#define	OR1200_ICTAG			#OR1200_ICSIZE-#OR1200_ICLS	
#define	OR1200_ICTAG_W			18
#endif








#ifdef OR1200_DC_1W_32KB
 #define OR1200_DCLS		5
#else
 #define OR1200_DCLS		4
#endif




#define OR1200_DC_WRITETHROUGH






#define OR1200_SPRGRP_DC_ADR_WIDTH 3





#ifdef OR1200_DC_1W_4KB
#define OR1200_DCSIZE			12			
#define OR1200_DCINDX			#OR1200_DCSIZE-2	
#define OR1200_DCINDXH			#OR1200_DCSIZE-1	
#define OR1200_DCTAGL			#OR1200_DCINDXH+1	
#define	OR1200_DCTAG			#OR1200_DCSIZE-#OR1200_DCLS	
#define	OR1200_DCTAG_W			21
#endif
#ifdef OR1200_DC_1W_8KB
#define OR1200_DCSIZE			13			
#define OR1200_DCINDX			#OR1200_DCSIZE-2	
#define OR1200_DCINDXH			#OR1200_DCSIZE-1	
#define OR1200_DCTAGL			#OR1200_DCINDXH+1	
#define	OR1200_DCTAG			#OR1200_DCSIZE-#OR1200_DCLS	
#define	OR1200_DCTAG_W			20
#endif
#ifdef OR1200_DC_1W_16KB
#define OR1200_DCSIZE			14			
#define OR1200_DCINDX			#OR1200_DCSIZE-2	
#define OR1200_DCINDXH			#OR1200_DCSIZE-1	
#define OR1200_DCTAGL			#OR1200_DCINDXH+1	
#define	OR1200_DCTAG			#OR1200_DCSIZE-#OR1200_DCLS	
#define	OR1200_DCTAG_W			19
#endif
#ifdef OR1200_DC_1W_32KB
#define OR1200_DCSIZE			15			
#define OR1200_DCINDX			#OR1200_DCSIZE-2	
#define OR1200_DCINDXH			#OR1200_DCSIZE-1	
#define OR1200_DCTAGL			#OR1200_DCINDXH+1	
#define	OR1200_DCTAG			#OR1200_DCSIZE-#OR1200_DCLS	
#define	OR1200_DCTAG_W			18
#endif































#define OR1200_SB_IMPLEMENTED










#define OR1200_SB_LOG		2	
#define OR1200_SB_ENTRIES	4	












































































#define OR1200_CFGR_IMPLEMENTED


#define OR1200_SYS_FULL_DECODE




#define OR1200_VR_REV_BITS		5:0
#define OR1200_VR_RES1_BITS		15:6
#define OR1200_VR_CFG_BITS		23:16
#define OR1200_VR_VER_BITS		31:24




#define OR1200_UPR_UP_BITS		0
#define OR1200_UPR_DCP_BITS		1
#define OR1200_UPR_ICP_BITS		2
#define OR1200_UPR_DMP_BITS		3
#define OR1200_UPR_IMP_BITS		4
#define OR1200_UPR_MP_BITS		5
#define OR1200_UPR_DUP_BITS		6
#define OR1200_UPR_PCUP_BITS		7
#define OR1200_UPR_PMP_BITS		8
#define OR1200_UPR_PICP_BITS		9
#define OR1200_UPR_TTP_BITS		10
#define OR1200_UPR_FPP_BITS		11
#define OR1200_UPR_RES1_BITS		23:12
#define OR1200_UPR_CUP_BITS		31:24


#ifdef OR1200_NO_DC
#else
#endif
#ifdef OR1200_NO_IC
#else
#endif
#ifdef OR1200_NO_DMMU
#else
#endif
#ifdef OR1200_NO_IMMU
#else
#endif
#ifdef OR1200_MAC_IMPLEMENTED
#else
#endif
#ifdef OR1200_DU_IMPLEMENTED
#else
#endif
#ifdef OR1200_PM_IMPLEMENTED
#else
#endif
#ifdef OR1200_PIC_IMPLEMENTED
#else
#endif
#ifdef OR1200_TT_IMPLEMENTED
#else
#endif
#ifdef OR1200_FPU_IMPLEMENTED
#else
#endif


#define OR1200_CPUCFGR_NSGF_BITS	3:0
#define OR1200_CPUCFGR_HGF_BITS     4
#define OR1200_CPUCFGR_OB32S_BITS	5
#define OR1200_CPUCFGR_OB64S_BITS	6
#define OR1200_CPUCFGR_OF32S_BITS	7
#define OR1200_CPUCFGR_OF64S_BITS	8
#define OR1200_CPUCFGR_OV64S_BITS	9
#define OR1200_CPUCFGR_RES1_BITS	31:10


#ifdef OR1200_RFRAM_16REG
#else
#endif
#ifdef OR1200_FPU_IMPLEMENTED
#else
#endif



#define OR1200_DMMUCFGR_NTW_BITS	1:0
#define OR1200_DMMUCFGR_NTS_BITS	4:2
#define OR1200_DMMUCFGR_NAE_BITS	7:5
#define OR1200_DMMUCFGR_CRI_BITS	8
#define OR1200_DMMUCFGR_PRI_BITS	9
#define OR1200_DMMUCFGR_TEIRI_BITS	10
#define OR1200_DMMUCFGR_HTR_BITS	11
#define OR1200_DMMUCFGR_RES1_BITS	31:12


#ifdef OR1200_NO_DMMU
#else
#endif


#define OR1200_IMMUCFGR_NTW_BITS	1:0
#define OR1200_IMMUCFGR_NTS_BITS	4:2
#define OR1200_IMMUCFGR_NAE_BITS	7:5
#define OR1200_IMMUCFGR_CRI_BITS	8
#define OR1200_IMMUCFGR_PRI_BITS	9
#define OR1200_IMMUCFGR_TEIRI_BITS	10
#define OR1200_IMMUCFGR_HTR_BITS	11
#define OR1200_IMMUCFGR_RES1_BITS	31:12


#ifdef OR1200_NO_IMMU
#else
#endif


#define OR1200_DCCFGR_NCW_BITS		2:0
#define OR1200_DCCFGR_NCS_BITS		6:3
#define OR1200_DCCFGR_CBS_BITS		7
#define OR1200_DCCFGR_CWS_BITS		8
#define OR1200_DCCFGR_CCRI_BITS		9
#define OR1200_DCCFGR_CBIRI_BITS	10
#define OR1200_DCCFGR_CBPRI_BITS	11
#define OR1200_DCCFGR_CBLRI_BITS	12
#define OR1200_DCCFGR_CBFRI_BITS	13
#define OR1200_DCCFGR_CBWBRI_BITS	14
#define OR1200_DCCFGR_RES1_BITS	31:15


#ifdef OR1200_NO_DC
#else
#define OR1200_DCCFGR_NCS (#OR1200_DCTAG)	
#ifdef OR1200_DC_WRITETHROUGH
#else
#endif
#ifdef OR1200_DC_WRITETHROUGH
#else
#endif
#endif


#define OR1200_ICCFGR_NCW_BITS		2:0
#define OR1200_ICCFGR_NCS_BITS		6:3
#define OR1200_ICCFGR_CBS_BITS		7
#define OR1200_ICCFGR_CWS_BITS		8
#define OR1200_ICCFGR_CCRI_BITS		9
#define OR1200_ICCFGR_CBIRI_BITS	10
#define OR1200_ICCFGR_CBPRI_BITS	11
#define OR1200_ICCFGR_CBLRI_BITS	12
#define OR1200_ICCFGR_CBFRI_BITS	13
#define OR1200_ICCFGR_CBWBRI_BITS	14
#define OR1200_ICCFGR_RES1_BITS	31:15


#ifdef OR1200_NO_IC
#else
#define OR1200_ICCFGR_NCS (#OR1200_ICTAG)	
#endif


#define OR1200_DCFGR_NDP_BITS		3:0
#define OR1200_DCFGR_WPCI_BITS		4
#define OR1200_DCFGR_RES1_BITS		31:5


#ifdef OR1200_DU_HWBKPTS
#ifdef OR1200_DU_DWCR0
#else
#endif
#else
#endif


















#endif

