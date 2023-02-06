#include "MOOSELearningApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MOOSELearningApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

MOOSELearningApp::MOOSELearningApp(InputParameters parameters) : MooseApp(parameters)
{
  MOOSELearningApp::registerAll(_factory, _action_factory, _syntax);
}

MOOSELearningApp::~MOOSELearningApp() {}

void
MOOSELearningApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"MOOSELearningApp"});
  Registry::registerActionsTo(af, {"MOOSELearningApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MOOSELearningApp::registerApps()
{
  registerApp(MOOSELearningApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MOOSELearningApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MOOSELearningApp::registerAll(f, af, s);
}
extern "C" void
MOOSELearningApp__registerApps()
{
  MOOSELearningApp::registerApps();
}
