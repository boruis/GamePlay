#ifndef LUA_PHYSICSVEHICLE_H_
#define LUA_PHYSICSVEHICLE_H_

namespace gameplay
{

// Lua bindings for PhysicsVehicle.
int lua_PhysicsVehicle_addCollisionListener(lua_State* state);
int lua_PhysicsVehicle_addWheel(lua_State* state);
int lua_PhysicsVehicle_collidesWith(lua_State* state);
int lua_PhysicsVehicle_getBrakingForce(lua_State* state);
int lua_PhysicsVehicle_getCollisionShape(lua_State* state);
int lua_PhysicsVehicle_getDrivingForce(lua_State* state);
int lua_PhysicsVehicle_getNode(lua_State* state);
int lua_PhysicsVehicle_getNumWheels(lua_State* state);
int lua_PhysicsVehicle_getRigidBody(lua_State* state);
int lua_PhysicsVehicle_getShapeType(lua_State* state);
int lua_PhysicsVehicle_getSpeedKph(lua_State* state);
int lua_PhysicsVehicle_getSteeringGain(lua_State* state);
int lua_PhysicsVehicle_getType(lua_State* state);
int lua_PhysicsVehicle_getWheel(lua_State* state);
int lua_PhysicsVehicle_isDynamic(lua_State* state);
int lua_PhysicsVehicle_isEnabled(lua_State* state);
int lua_PhysicsVehicle_isKinematic(lua_State* state);
int lua_PhysicsVehicle_removeCollisionListener(lua_State* state);
int lua_PhysicsVehicle_setBrakingForce(lua_State* state);
int lua_PhysicsVehicle_setDrivingForce(lua_State* state);
int lua_PhysicsVehicle_setEnabled(lua_State* state);
int lua_PhysicsVehicle_setSteeringGain(lua_State* state);
int lua_PhysicsVehicle_update(lua_State* state);

void luaRegister_PhysicsVehicle();

}

#endif