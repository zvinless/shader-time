#version 330

uniform sampler2D tex;
uniform sampler2D gradient;
in vec2 texcoord;
out vec4 color;

void main()
{
    vec4 main = texture(tex, texcoord);
    float gradient = texture(gradient, texcoord).r;
    color = main * gradient;
}
