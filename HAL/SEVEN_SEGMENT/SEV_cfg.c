/*
 * SEV_cfg.c
 *
 *  Created on: Jul 30, 2024
 *      Author: Mohamed
 */
#include "SEV_cfg.h"
#include "../../MCAL/DIO/DIO.h"
Sev_config SEV_ConfigSet[MAX_SEV_SEGMENT]= {    

    {   
            /* A */       /* B */        /* C */         /* D */        /* E */         /* F */         /* G */  
        {DIO_PIN_NUM_0, DIO_PIN_NUM_1, DIO_PIN_NUM_2, DIO_PIN_NUM_3, DIO_PIN_NUM_4, DIO_PIN_NUM_5, DIO_PIN_NUM_6},
        DIO_PIN_NUM_7,
        Common_Cathode
    }

    ,

    {       /* A */       /* B */        /* C */         /* D */        /* E */         /* F */         /* G */  
        {DIO_PIN_NUM_8, DIO_PIN_NUM_9, DIO_PIN_NUM_10, DIO_PIN_NUM_11, DIO_PIN_NUM_12, DIO_PIN_NUM_13, DIO_PIN_NUM_14},
        DIO_PIN_NUM_15,
        Common_Anode
    }

};



