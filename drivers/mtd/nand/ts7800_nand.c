/*
 * Based on arch/arm/mach-orion5x/ts78xx-setup.c from Linux
 * by Alexander Clouter <alex@digriz.org.uk>.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/io.h>
#include <nand.h>

/*
 * hardware specific access to control-lines
 *
 * ctrl:
 * NAND_NCE: bit 0 -> bit 2
 * NAND_CLE: bit 1 -> bit 1
 * NAND_ALE: bit 2 -> bit 0
 */
static void ts78xx_ts_nand_cmd_ctrl(struct mtd_info *mtd, int cmd,
			unsigned int ctrl)
{
	struct nand_chip *this = mtd->priv;

	if (ctrl & NAND_CTRL_CHANGE) {
		unsigned char bits;

		bits = (ctrl & NAND_NCE) << 2;
		bits |= ctrl & NAND_CLE;
		bits |= (ctrl & NAND_ALE) >> 2;

		writeb((readb(TS_NAND_CTRL) & ~0x7) | bits, TS_NAND_CTRL);
	}

	if (cmd != NAND_CMD_NONE)
		writeb(cmd, this->IO_ADDR_W);
}

static int ts78xx_ts_nand_dev_ready(struct mtd_info *mtd)
{
	return readb(TS_NAND_CTRL) & 0x20;
}

int board_nand_init(struct nand_chip *nand)
{
	nand->options = NAND_USE_FLASH_BBT;
	nand->ecc.mode = NAND_ECC_SOFT;
	nand->cmd_ctrl = ts78xx_ts_nand_cmd_ctrl;
	nand->dev_ready = ts78xx_ts_nand_dev_ready;
	nand->chip_delay = 15;
	return 0;
}
