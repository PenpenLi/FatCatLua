#ifdef GL_ES
precision mediump float;
#endif

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

uniform vec2 resolution;
uniform vec4 factorX;

const float blurSize = 1.0/512.0;
const float intensity = 0.35;
void main()
{
   vec4 sum = vec4(0);
   vec2 texcoord = v_texCoord.xy;
   int j;
   int i;

  
   //blur tutorial
   // blur in y (vertical)
   // take nine samples, with the distance blurSize between them
   sum += texture2D(CC_Texture0, vec2(texcoord.x - 4.0*blurSize, texcoord.y)) * 0.05;
   sum += texture2D(CC_Texture0, vec2(texcoord.x - 3.0*blurSize, texcoord.y)) * 0.09;
   sum += texture2D(CC_Texture0, vec2(texcoord.x - 2.0*blurSize, texcoord.y)) * 0.12;
   sum += texture2D(CC_Texture0, vec2(texcoord.x - blurSize, texcoord.y)) * 0.15;
   sum += texture2D(CC_Texture0, vec2(texcoord.x, texcoord.y)) * 0.16;
   sum += texture2D(CC_Texture0, vec2(texcoord.x + blurSize, texcoord.y)) * 0.15;
   sum += texture2D(CC_Texture0, vec2(texcoord.x + 2.0*blurSize, texcoord.y)) * 0.12;
   sum += texture2D(CC_Texture0, vec2(texcoord.x + 3.0*blurSize, texcoord.y)) * 0.09;
   sum += texture2D(CC_Texture0, vec2(texcoord.x + 4.0*blurSize, texcoord.y)) * 0.05;
	
	// blur in y (vertical)
   // take nine samples, with the distance blurSize between them
   sum += texture2D(CC_Texture0, vec2(texcoord.x, texcoord.y - 4.0*blurSize)) * 0.05;
   sum += texture2D(CC_Texture0, vec2(texcoord.x, texcoord.y - 3.0*blurSize)) * 0.09;
   sum += texture2D(CC_Texture0, vec2(texcoord.x, texcoord.y - 2.0*blurSize)) * 0.12;
   sum += texture2D(CC_Texture0, vec2(texcoord.x, texcoord.y - blurSize)) * 0.15;
   sum += texture2D(CC_Texture0, vec2(texcoord.x, texcoord.y)) * 0.16;
   sum += texture2D(CC_Texture0, vec2(texcoord.x, texcoord.y + blurSize)) * 0.15;
   sum += texture2D(CC_Texture0, vec2(texcoord.x, texcoord.y + 2.0*blurSize)) * 0.12;
   sum += texture2D(CC_Texture0, vec2(texcoord.x, texcoord.y + 3.0*blurSize)) * 0.09;
   sum += texture2D(CC_Texture0, vec2(texcoord.x, texcoord.y + 4.0*blurSize)) * 0.05;
//0.937,0.604,0.282   gray 0.299, 0.587, 0.114
//sum*intensity + 
  	vec4 v_orColor = sum*intensity + v_fragmentColor*texture2D(CC_Texture0, texcoord);
	//float gray = dot(v_orColor.rgb, vec3(0.937,0.604,0.282));
   //increase blur with intensity!  
   gl_FragColor = vec4(v_orColor.r*factorX.r, v_orColor.g*factorX.g, v_orColor.b*factorX.b, v_orColor.a*factorX.a); 
 
}