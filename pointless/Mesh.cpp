#include "Mesh.h"
#include "Shader.h"

using namespace Pointless;

void Mesh::bake() {
	glGenBuffers(1, &vertexBufferPosition);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferPosition);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Pointless::vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    
    glGenBuffers(1, &vertexBufferUv);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferUv);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Pointless::vec2) * uvs.size(), &uvs[0], GL_STATIC_DRAW);
    
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint16_t) * indicies.size(), &indicies[0], GL_STATIC_DRAW);
    
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
    
    glEnableVertexAttribArray(Pointless::Shader::ATTRIB_VERTEX);
    glEnableVertexAttribArray(Pointless::Shader::ATTRIB_TEXCOORD0);
    
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferPosition);
    glVertexAttribPointer(Pointless::Shader::ATTRIB_VERTEX,    3, GL_FLOAT, GL_FALSE, sizeof(Pointless::vec3), 0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferUv);
    glVertexAttribPointer(Pointless::Shader::ATTRIB_TEXCOORD0, 2, GL_FLOAT, GL_FALSE, sizeof(Pointless::vec2), 0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}