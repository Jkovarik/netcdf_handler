
// -*- mode: c++; c-basic-offset:4 -*-

// This file is part of nc_handler, a data handler for the OPeNDAP data
// server. 

// Copyright (c) 2002,2003 OPeNDAP, Inc.
// Author: James Gallagher <jgallagher@opendap.org>
//
// This is free software; you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free
// Software Foundation; either version 2.1 of the License, or (at your
// option) any later version.
// 
// This software is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
// License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// You can contact OPeNDAP, Inc. at PO Box 112, Saunderstown, RI. 02874-0112.
 
// NCContainerPersistence.cc

#include <sstream>
#include <fstream>
#include <iostream>

using std::stringstream ;
using std::ifstream ;

#include "NCContainerPersistence.h"
#include "DODSContainer.h"
#include "TheDODSKeys.h"
#include "DODSContainerPersistenceException.h"
#include "DODSInfo.h"

#define NC_CATALOG_ROOT_KEY "NC.Catalog.Root"

NCContainerPersistence::NCContainerPersistence( const string &n )
    : DODSContainerPersistence( n )
{
    bool found = false ;
    string key = NC_CATALOG_ROOT_KEY ;
    _nc_base = TheDODSKeys::TheKeys()->get_key( key, found ) ;
    if( _nc_base == "" )
    {
	string s = key + " not defined in key file" ;
	DODSContainerPersistenceException pe ;
	pe.set_error_description( s ) ;
	throw pe;
    }
}

NCContainerPersistence::~NCContainerPersistence()
{
}

void
NCContainerPersistence::look_for( DODSContainer &d )
{
    d.set_valid_flag( true ) ;
    d.set_real_name( _nc_base + "/" + d.get_symbolic_name() ) ;
    d.set_container_type( "nc" ) ;
}

void
NCContainerPersistence::add_container( string s_name,
                                            string r_ame,
					    string type )
{
    throw DODSContainerPersistenceException( "Unable to add a container to NC Persistence" ) ;
}

bool
NCContainerPersistence::rem_container( const string &s_name )
{
    throw DODSContainerPersistenceException( "Unable to remove a container from NC Persistence" ) ;
    return false ;
}

void
NCContainerPersistence::show_containers( DODSInfo &info )
{
    info.add_data( get_name() ) ;
    info.add_data( "\n" ) ;
    info.add_data( "    For a list of NC containers please traverse the Catalog\n" ) ;
}

// $Log: NCContainerPersistence.cc,v $
