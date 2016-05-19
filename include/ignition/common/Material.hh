/*
 * Copyright (C) 2012-2016 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef IGNITION_COMMON_MATERIAL_HH_
#define IGNITION_COMMON_MATERIAL_HH_

#include <iostream>
#include <string>
#include <ignition/common/EnumIface.hh>
#include <ignition/common/Color.hh>

namespace ignition
{
  namespace common
  {
    /// \brief Encapsulates description of a material
    class IGNITION_COMMON_VISIBLE Material
    {
      /// \def Shade modes
      /// \brief Enumeration of shade mode types
      public: enum ShadeMode
      {
        /// \internal
        /// \brief Indicator used to create an iterator over the
        /// enum. Do not use this.
        SHADE_MODE_BEGIN = 0,

        /// \brief Flat shading
        FLAT = 0,

        /// \brief Gouraud shading
        GOURAUD = 1,

        /// \brief Phong shading
        PHONG = 2,

        /// \brief Blinn shading
        BLINN = 3,

        /// \internal
        /// \brief Indicator used to create an iterator over the
        /// enum. Do not use this.
        SHADE_MODE_END
      };

      /// \def Blend modes
      /// \brief Enumeration of blend mode types
      public: enum BlendMode
      {
        /// \internal
        /// \brief Indicator used to create an iterator over the
        /// enum. Do not use this.
        BLEND_MODE_BEGIN = 0,

        /// \brief Add mode
        ADD = 0,

        /// \brief Modulate mode
        MODULATE = 1,

        /// \brief Replace mode
        REPLACE = 2,

        /// \internal
        /// \brief Indicator used to create an iterator over the
        /// enum. Do not use this.
        BLEND_MODE_END
      };

      /// \brief Constructor
      public: Material();

      /// \brief Destructor
      public: virtual ~Material();

      /// \brief Create a material with a default color
      /// \param[in] _clr Color of the material
      public: Material(const Color &_clr);

      /// \brief Get the name of the material
      /// \return The name of the material
      public: std::string Name() const;

      /// \brief Set a texture image
      /// \param[in] _tex The name of the texture, which must be in the
      /// resource path
      public: void SetTextureImage(const std::string &_tex);

      /// \brief Set a texture image
      /// \param[in] _tex The name of the texture
      /// \param[in] _resourcePath Path which contains _tex
      public: void SetTextureImage(const std::string &_tex,
                                   const std::string &_resourcePath);

      /// \brief Get a texture image
      /// \return The name of the texture image (if one exists) or an empty
      /// string
      public: std::string TextureImage() const;

      /// \brief Set the ambient color
      /// \param[in] _clr The ambient color
      public: void SetAmbient(const Color &_clr);

      /// \brief Get the ambient color
      /// \return The ambient color
      public: Color Ambient() const;

      /// \brief Set the diffuse color
      /// \param[in] _clr The diffuse color
      public: void SetDiffuse(const Color &_clr);

      /// \brief Get the diffuse color
      /// \return The diffuse color
      public: Color Diffuse() const;

      /// \brief Set the specular color
      /// \param[in] _clr The specular color
      public: void SetSpecular(const Color &_clr);

      /// \brief Get the specular color
      /// \return The specular color
      public: Color Specular() const;

      /// \brief Set the emissive color
      /// \param[in] _clr The emissive color
      public: void SetEmissive(const Color &_clr);

      /// \brief Get the emissive color
      /// \return The emissive color
      public: Color Emissive() const;

      /// \brief Set the transparency percentage (0..1)
      /// \param[in] _t The amount of transparency (0..1)
      public: void SetTransparency(double _t);

      /// \brief Get the transparency percentage (0..1)
      /// \return The transparency percentage
      public: double Transparency() const;

      /// \brief Set the shininess
      /// \param[in] _t The shininess value
      public: void SetShininess(double _t);

      /// \brief Get the shininess
      /// \return The shininess value
      public: double Shininess() const;

      /// \brief Set the blende factors. Will be interpreted as:
      ///        (texture * _srcFactor) + (scene_pixel * _dstFactor)
      /// \param[in] _srcFactor The source factor
      /// \param[in] _dstFactor The destination factor
      public: void SetBlendFactors(double _srcFactor, double _dstFactor);

      /// \brief Get the blend factors
      /// \param[in] _srcFactor Source factor is returned in this variable
      /// \param[in] _dstFactor Destination factor is returned in this variable
      public: void BlendFactors(double &_srcFactor, double &_dstFactor);

      /// \brief Set the blending mode
      /// \param[in] _b the blend mode
      public: void SetBlend(BlendMode _b);

      /// \brief Get the blending mode
      /// \return the blend mode
      public: BlendMode Blend() const;

      /// \brief Set the shading mode
      /// param[in] the shading mode
      public: void SetShade(ShadeMode _b);

      /// \brief Get the shading mode
      /// \return the shading mode
      public: ShadeMode Shade() const;

      /// \brief Set the point size
      /// \param[in] _size the size
      public: void SetPointSize(double _size);

      /// \brief Get the point size
      /// \return the point size
      public: double PointSize() const;

      /// \brief Set depth write
      /// \param[in] _value the depth write enabled state
      public: void SetDepthWrite(bool _value);

      /// \brief Get depth write
      /// \return the depth write enabled state
      public: bool DepthWrite() const;

      /// \brief Set lighting enabled
      /// \param[in] _value the lighting enabled state
      public: void SetLighting(bool _value);

      /// \brief Get lighting enabled
      /// \return the lighting enabled state
      public: bool Lighting() const;

      /// \brief Stream insertion operator
      /// param[in] _out the output stream to extract from
      /// param[out] _m the material information
      public: friend std::ostream &operator<<(std::ostream &_out,
                  const ignition::common::Material &_m)
              {
                _out << "Material:\n";
                _out << "  Name: " << _m.name << "\n";
                _out << "  Texture: " << _m.texImage << "\n";
                _out << "  Ambient: " << _m.ambient << "\n";
                _out << "  Diffuse: " << _m.diffuse << "\n";
                _out << "  Specular: " << _m.specular << "\n";
                _out << "  Emissive: " << _m.emissive << "\n";
                _out << "  Transparency: " << _m.transparency << "\n";
                _out << "  Shininess: " << _m.shininess << "\n";
                _out << "  BlendMode: "
                  << EnumIface<BlendMode>::Str(_m.blendMode) << "\n";
                _out << "  ShadeMode: "
                  << EnumIface<ShadeMode>::Str(_m.shadeMode) << "\n";
                _out << "  DepthWrite: " << _m.depthWrite << "\n";
                return _out;
              }

      /// \brief the name of the material
      protected: std::string name;

      /// \brief the texture image file name
      protected: std::string texImage;

      /// \brief the ambient light color
      protected: Color ambient;

      /// \brief the diffuse ligth color
      protected: Color diffuse;

      /// \brief the specular light color
      protected: Color specular;

      /// \brief the emissive light color
      protected: Color emissive;

      /// \brief transparency value in the range 0 to 1
      protected: double transparency;

      /// \brief shininess value (0 to 1)
      protected: double shininess;

      /// \brief point size
      protected: double pointSize;

      /// \brief blend mode
      protected: BlendMode blendMode;

      /// \brief the shade mode
      protected: ShadeMode shadeMode;

      /// \brief the total number of instanciated Material instances
      private: static unsigned int counter;

      /// \brief flag to perform depth buffer write
      private: bool depthWrite;

      private: bool lighting;

      /// \brief source blend factor
      private: double srcBlendFactor;

      /// \brief destination blend factor
      private: double dstBlendFactor;
    };
  }
}
#endif
