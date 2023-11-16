#pragma once

// BulletCollisionHandler.h
#ifndef BULLET_COLLISION_HANDLER_H
#define BULLET_COLLISION_HANDLER_H

#include <vector>

#include "btBulletDynamicsCommon.h"

class BulletCollisionHandler 
{
    public:
        BulletCollisionHandler();
        ~BulletCollisionHandler();

        void createDynamicsWorld();
        void deleteDynamicsWorld();

        void cleanRigidBody(btRigidBody* body);
        void updateActiveObject(MFnMesh* mesh);
        void updateActiveObjectProxy(const btTransform& startTransform);
        void constrainBodies(btRigidBody* mainBody, btRigidBody* proxyBody);
        void updateColliders(std::vector<MFnMesh*> collidersMFnMeshes);
        btRigidBody* createFullColliderFromMFnMesh(MFnMesh* mfnMesh);
        btRigidBody* createFullActiveRigidBodyFromMFnMesh(MFnMesh* mfnMesh);


        void setProxyObjectPosition(float x, float y, float z);
        MMatrix getProxyObjectTransformMMatrix();

        btCollisionShape* convertMFnMeshToCollisionShape(MFnMesh * mfnMesh);

        btTransform convertMayaToBulletMatrix(const MMatrix& mayaMatrix);
        MMatrix convertBulletToMayaMatrix(const btTransform& bulletTransform);

        btTransform getBulletTransformFromMFnMeshTransform(MFnMesh* mfnMesh);

        void updateWorld(float framesToUpdate);

        MObject createMayaMeshFromBulletRigidBody(btRigidBody* rigidBody);

        btRigidBody* activeRigidBody;
        btRigidBody* proxyRigidBody;
        std::vector<btRigidBody*> colliders;

        btDiscreteDynamicsWorld* dynamicsWorld;
    private:
        btBroadphaseInterface* broadphase;
        btDefaultCollisionConfiguration* collisionConfiguration;
        btCollisionDispatcher* dispatcher;
        btSequentialImpulseConstraintSolver* solver;
};

#endif // BULLET_COLLISION_HANDLER_H
