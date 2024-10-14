#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment fragColor
out vec4 finalColor;

// NOTE: Add here your custom variables

void main()
{
    // Texel color fetching form texture sampler
    vec4 texelColor = texture(texture0, fragTexCoord);

    // NOTE: Implement here your faragment shader code

    finalColor = texelColor*colDiffue;
}
