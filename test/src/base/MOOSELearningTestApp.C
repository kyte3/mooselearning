//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MOOSELearningTestApp.h"
#include "MOOSELearningApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
MOOSELearningTestApp::validParams()
{
  InputParameters params = MOOSELearningApp::validParams();
  return params;
}

MOOSELearningTestApp::MOOSELearningTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MOOSELearningTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MOOSELearningTestApp::~MOOSELearningTestApp() {}

void
MOOSELearningTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MOOSELearningApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MOOSELearningTestApp"});
    Registry::registerActionsTo(af, {"MOOSELearningTestApp"});
  }
}

void
MOOSELearningTestApp::registerApps()
{
  registerApp(MOOSELearningApp);
  registerApp(MOOSELearningTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MOOSELearningTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MOOSELearningTestApp::registerAll(f, af, s);
}
extern "C" void
MOOSELearningTestApp__registerApps()
{
  MOOSELearningTestApp::registerApps();
}
