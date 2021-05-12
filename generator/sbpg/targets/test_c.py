#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Generator for c tests target.
"""

from sbpg.targets.templating import *
from sbpg.targets.c import *
from sbpg.targets.common import *
import base64

TEST_TEMPLATE_NAME = "sbp_c_test.c.j2"
CPP_TEST_TEMPLATE_NAME = "sbp_cpp_test.cc.j2"
CHECK_SUITES_TEMPLATE_NAME = "sbp_c_suites.h.j2"
CHECK_MAIN_TEMPLATE_NAME = "sbp_c_main.c.j2"

def b64_decode(field):
    return base64.standard_b64decode(field)

def strEscape(value):
    return ",".join(["(char)" + str(ord(ch)) for ch in value])

def convert_upper(value):
    return convert_unpacked(value)[4:-2].upper()

JENV.filters['commentify'] = commentify
JENV.filters['mk_packed_id'] = mk_packed_id
JENV.filters['mk_size'] = mk_size
JENV.filters['convert_packed'] = convert_packed
JENV.filters['convert_unpacked'] = convert_unpacked
JENV.filters['convert_upper'] = convert_upper
JENV.filters['type'] = type
JENV.filters['str_escape'] = strEscape
JENV.filters['to_str'] = to_str
JENV.filters['sorted'] = sorted

JENV.tests['string_type'] = string_type
JENV.tests['array_type'] = array_type
JENV.tests['dict_type'] = dict_type
JENV.tests['float_type'] = float_type
JENV.tests['empty'] = is_empty

def render_source(output_dir, package_spec):
  """
  Render and output to a directory given a package specification.
  """
  path, name = package_spec.filepath
  destination_filename = "%s/%s.c" % (output_dir, name)
  py_template = JENV.get_template(TEST_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(s=package_spec,
                               description=package_spec.description,
                               pkg_name=package_spec.package,
                               include=package_spec.package.split('.')[1],
                               filepath="/".join(package_spec.filepath) + ".yaml"))
  destination_filename = "%s/cpp/%s.cc" % (output_dir, name)
  py_template = JENV.get_template(CPP_TEST_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(s=package_spec,
                               description=package_spec.description,
                               pkg_name=package_spec.package,
                               include=package_spec.package.split('.')[1],
                               filepath="/".join(package_spec.filepath) + ".yaml"))


def render_check_suites(output_dir, all_package_specs):
  destination_filename = "%s/%s.h" % (output_dir, "check_suites")
  py_template = JENV.get_template(CHECK_SUITES_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(package_suites=all_package_specs))


def render_check_main(output_dir, all_package_specs):
  destination_filename = "%s/%s.c" % (output_dir, "check_main")
  py_template = JENV.get_template(CHECK_MAIN_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(package_suites=all_package_specs))
