//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "roadrunnerTestApp.h"
#include "roadrunnerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<roadrunnerTestApp>()
{
  InputParameters params = validParams<roadrunnerApp>();
  return params;
}

roadrunnerTestApp::roadrunnerTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  roadrunnerApp::registerObjectDepends(_factory);
  roadrunnerApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  roadrunnerApp::associateSyntaxDepends(_syntax, _action_factory);
  roadrunnerApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  roadrunnerApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    roadrunnerTestApp::registerObjects(_factory);
    roadrunnerTestApp::associateSyntax(_syntax, _action_factory);
    roadrunnerTestApp::registerExecFlags(_factory);
  }
}

roadrunnerTestApp::~roadrunnerTestApp() {}

void
roadrunnerTestApp::registerApps()
{
  registerApp(roadrunnerApp);
  registerApp(roadrunnerTestApp);
}

void
roadrunnerTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
roadrunnerTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
roadrunnerTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
roadrunnerTestApp__registerApps()
{
  roadrunnerTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
roadrunnerTestApp__registerObjects(Factory & factory)
{
  roadrunnerTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
roadrunnerTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  roadrunnerTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
roadrunnerTestApp__registerExecFlags(Factory & factory)
{
  roadrunnerTestApp::registerExecFlags(factory);
}
