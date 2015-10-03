//
//		OuterProduct.cc	This file is a part of the IKAROS project
//						Implements a modules that calculates the outer product of two inputs
//
//    Copyright (C) 2004 Christian Balkenius
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//	Created: 2004-03-22
//


#include "OuterProduct.h"

using namespace ikaros;

void
OuterProduct::Init()
{
    input1		=	GetInputArray("INPUT1");
    input2		=	GetInputArray("INPUT2");
    output		=	GetOutputMatrix("OUTPUT");
    size1		=	GetOutputSizeX("OUTPUT");
    size2		=	GetOutputSizeY("OUTPUT");
}



void OuterProduct::SetSizes()
{
    int sz1 = GetInputSize("INPUT1");
    int sz2 = GetInputSize("INPUT2");

    if (sz1 == unknown_size || sz2 == unknown_size)
        return;

    SetOutputSize("OUTPUT", sz1, sz2);
}



void
OuterProduct::Tick()
{
    outer(output, input1, input2, size1, size2);
}


