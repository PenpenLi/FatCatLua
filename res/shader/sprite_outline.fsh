
varying vec2 v_texCoord;
varying vec4 v_fragmentColor;

uniform vec3 u_outlineColor;
uniform float u_threshold;
uniform float u_radius;

void main()
{
    float radius = u_radius;
    vec4 accum = vec4(0.0);
    vec4 normal = vec4(0.0);
    
    normal = texture2D(CC_Texture0, vec2(v_texCoord.x, v_texCoord.y));
    
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x - radius, v_texCoord.y - radius));
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x + radius, v_texCoord.y - radius));
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x + radius, v_texCoord.y + radius));
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x - radius, v_texCoord.y + radius));
    
    accum *= u_threshold;
    accum.rgb =  u_outlineColor * accum.a;
    accum.a = 1.0;
    
    normal = ( accum * (1.0 - normal.a)) + (normal * normal.a);
    
    //normal.r<0.1&&normal.g<0.1&&normal.b<0.1
    
	//if(normal.r<0.1&&normal.g<0.1&&normal.b<0.1){
	//	normal.a = 0;
	//}
	float x = step(0.1,normal.r);
	x += step(0.1,normal.g);
	x += step(0.1,normal.b);
	normal.a *= step(3.0,x);
    gl_FragColor = v_fragmentColor * normal;
}

