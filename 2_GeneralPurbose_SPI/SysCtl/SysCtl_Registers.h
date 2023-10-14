/** 
* @file  SysCtl_Registers.h
* @brief This file contains all the registers the System Control module contains
*
* you will need to include that file to access your SysCtl registers.
* The registers here represented as a struct of registers. which is the most reusable
* way to represent your registers in your code.
* This file contains all the registers that TIVA-C System Control module have.
* porting this module to another SoC will need to check the arrengement of the registers
* to fit your Soc.
*
* @author Abdulrahman Yasser
* @date 12/10/2023
* @version 1.0.0
* @copyright GNU Public License
* @bug it doesn't include all the registers, it only have the ones that we used in that module.
* Still need repair if it's usage extended
* @subsection Step1 Cmake
* @subsection Step2 make
* 
* @note                 THIS SOFTWARE IS PROVIDED BY Abdulrahman Yasser : COMPANY "AS IS" AND ANY EXPRESSED
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL BENINGO ENGINEERING OR ITS CONTRIBUTORS BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
* Compiler              GCC
* Target                TM4C123GH6PM
*
*****************************************************************************/
#include "Std_Types.h"

#define SysCtl_RCGC_Base    0x400FE600      /**< Base address for Run Mode Clock Gating Control registers in System Control module.*/

/**
* @brief a typedef for all the register in System Control module
* @bug it's only usable till RCGCI2C, after that it needs a space because there
* is a reserved 4 bytes i guess, go back to the register table in the datasheet
* @todo go back to datasheet and represent the whole registers in the right way to fix
* the bug
* \b Example:
* @code
*    volatile SysCtl_Module_regs* const my_SysCtl_RCGC_Registers_g = (SysCtl_Module_regs*)SysCtl_RCGC_Base;
*    my_SysCtl_RCGC_Registers_g->RCGCSSI |=  1 << SPIConfigs[i].channelNumber ;
* @endcode
* @see my_SysCtl_RCGC_Registers_g
 */
typedef struct {
    volatile uint32 RCGCWD;         /**< Watchdog Timer Run Mode Clock Gating Control.*/
    volatile uint32 RCGCTIMER;      /**< 16/32-Bit General-Purpose Timer Run Mode Clock Gating Control.*/
    volatile uint32 RCGCGPIO;       /**< General-Purpose Input/Output Run Mode Clock Gating Control.*/
    volatile uint32 RCGCDMA;        /**< Micro Direct Memory Access Run Mode Clock Gating Control.*/
    volatile uint32 NotUsed;        
    volatile uint32 RCGCHIB;        /**< Hibernation Run Mode Clock Gating Control.*/
    volatile uint32 RCGCUART;       /**< Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating Control.*/
    volatile uint32 RCGCSSI;        /**< Synchronous Serial Interface Run Mode Clock Gating Control.*/
    volatile uint32 RCGCI2C;        /**< Inter-Integrated Circuit Run Mode Clock Gating Control.*/
    volatile uint32 RCGCUSB;        /**< Universal Serial Bus Run Mode Clock Gating Control.*/
    volatile uint32 RCGCCAN;        /**< Controller Area Network Run Mode Clock Gating Control.*/
    volatile uint32 RCGCADC;        /**< Analog-to-Digital Converter Run Mode Clock Gating Control.*/
    volatile uint32 RCGCACMP;       /**< Analog Comparator Run Mode Clock Gating Control.*/
    volatile uint32 RCGCPWM;        /**< Pulse Width Modulator Run Mode Clock Gating Contro.*/
    volatile uint32 RCGCQEI;        /**< Quadrature Encoder Interface Run Mode Clock Gating Control.*/
    volatile uint32 RCGCEEPROM;     /**< EEPROM Run Mode Clock Gating Control.*/
    volatile uint32 RCGCWTIMER;     /**< 32/64-Bit Wide General-Purpose Timer Run Mode Clock Gating Control.*/
}SysCtl_Module_regs;

/**
* @brief a ggeneral variable for accessing RCGC_x registers
* @var volatile SysCtl_Module_regs* const my_SysCtl_RCGC_Registers_g
* \b Example:
* @code
*    volatile SysCtl_Module_regs* const my_SysCtl_RCGC_Registers_g = (SysCtl_Module_regs*)SysCtl_RCGC_Base;
*    my_SysCtl_RCGC_Registers_g->RCGCSSI |=  1 << SPIConfigs[i].channelNumber ;
* @see SysCtl_Module_regs
*/
volatile SysCtl_Module_regs* const my_SysCtl_RCGC_Registers_g = (SysCtl_Module_regs*)SysCtl_RCGC_Base;