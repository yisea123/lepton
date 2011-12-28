/*
The contents of this file are subject to the Mozilla Public License Version 1.1 
(the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS" basis, 
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License for the 
specific language governing rights and limitations under the License.

The Original Code is ______________________________________.

The Initial Developer of the Original Code is ________________________.
Portions created by ______________________ are Copyright (C) ______ _______________________.
All Rights Reserved.

Contributor(s): ______________________________________.

Alternatively, the contents of this file may be used under the terms of the eCos GPL license 
(the  [eCos GPL] License), in which case the provisions of [eCos GPL] License are applicable 
instead of those above. If you wish to allow use of your version of this file only under the
terms of the [eCos GPL] License and not to allow others to use your version of this file under 
the MPL, indicate your decision by deleting  the provisions above and replace 
them with the notice and other provisions required by the [eCos GPL] License. 
If you do not delete the provisions above, a recipient may use your version of this file under 
either the MPL or the [eCos GPL] License."
*/

/*===========================================
Includes
=============================================*/
#include "kernel/core/bin.h"

//see "bin/init.c"
int initd_main(int argc, char* argv[]);
//see "bin/lsh.c"
int lsh_main(int argc, char* argv[]);
//see "bin/mkfs.c"
int mkfs_main(int argc, char* argv[]);
//see "bin/mount.c"
int mount_main(int argc, char* argv[]);
//see "bin/umount.c"
int umount_main(int argc, char* argv[]);
/*===========================================
Global Declaration
=============================================*/
static const bin_t _bin_lst[]={
{         "initd",			                 initd_main,			10,			2048,			5},
{           "lsh",			                   lsh_main,			10,			2048,			5},
{          "mkfs",			                  mkfs_main,			10,			2048,			5},
{			 "mount",			                 mount_main,			10,			2048,			5},
{			"umount",			                umount_main,			10,			2048,			5}
};

const int bin_lst_size   = sizeof(_bin_lst)/sizeof(bin_t);
const bin_t* bin_lst = &_bin_lst[0];

/*===========================================
| End of Source  : bin_mkconf.c :
|---------------------------------------------
| Historic:
|---------------------------------------------
| Authors     | Date     | Comments
| $Log: not supported by cvs2svn $
| Revision 1.1  2009/03/30 11:18:54  jjp
| First import of tauon
|
|---------------------------------------------
=============================================*/