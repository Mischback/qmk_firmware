# SPDX-License-Identifier: GPL-2.0-or-later
# SPDX-FileCopyrightText: 2023 Mischback <mischback.dev@googlemail.com>
# SPDX-FileType: SOURCE

# Disable Audio and System Control features
#
# This overrides the default setting for this board.
#
# Not required for my personal setup.
EXTRAKEY_ENABLE = no

# Disable MAGIC keycodes
#
# Ref: https://docs.qmk.fm/#/keycodes_magic
# Ref: https://docs.qmk.fm/#/squeezing_avr?id=squeezing-the-most-out-of-avr
#
# Not required for my personal setup.
MAGIC_ENABLE = no

# Enable Link Time Optimization (LTO) to reduce build size.
#
# Ref: https://docs.qmk.fm/#/squeezing_avr?id=squeezing-the-most-out-of-avr
LTO_ENABLE = yes
