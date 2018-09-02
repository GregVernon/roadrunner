#include "roadrunnerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<roadrunnerApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

roadrunnerApp::roadrunnerApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  roadrunnerApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  roadrunnerApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  roadrunnerApp::registerExecFlags(_factory);
}

roadrunnerApp::~roadrunnerApp() {}

void
roadrunnerApp::registerApps()
{
  registerApp(roadrunnerApp);
}

void
roadrunnerApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"roadrunnerApp"});
}

void
roadrunnerApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"roadrunnerApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
roadrunnerApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
roadrunnerApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
roadrunnerApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
roadrunnerApp__registerApps()
{
  roadrunnerApp::registerApps();
}

extern "C" void
roadrunnerApp__registerObjects(Factory & factory)
{
  roadrunnerApp::registerObjects(factory);
}

extern "C" void
roadrunnerApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  roadrunnerApp::associateSyntax(syntax, action_factory);
}

extern "C" void
roadrunnerApp__registerExecFlags(Factory & factory)
{
  roadrunnerApp::registerExecFlags(factory);
}
