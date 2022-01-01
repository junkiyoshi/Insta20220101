#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(255);
	ofSetLineWidth(2);
	ofEnableDepthTest();

	this->font_size = 80;
	this->font.loadFont("fonts/Kazesawa-Bold.ttf", this->font_size, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(180);

	string word = "HAPPY NEW YEAR 2022!";
	int sample_count = 180;
	auto noise_param = ofRandom(1000);
	bool flag = true;

	for (int y = -350; y <= 350; y += 350) {

		ofPushMatrix();
		ofTranslate(0, y, 0);
		if (flag = !flag) {
			
			ofRotateY(ofGetFrameNum() * 2);
		}
		else {

			ofRotateY(360 - (ofGetFrameNum() * 2) % 360);
		}

		for (int i = 0; i < word.size(); i++) {

			ofPath chara_path = this->font.getCharacterAsPoints(word[i], true, false);
			vector<ofPolyline> outline = chara_path.getOutline();

			ofFill();
			ofSetColor(0);
			ofBeginShape();
			for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

				if (outline_index != 0) { ofNextContour(true); }

				auto vertices = outline[outline_index].getResampledByCount(sample_count).getVertices();
				for (auto& vertex : vertices) {

					auto location = vertex - glm::vec3(this->font_size * 0.5, this->font_size * -0.5, 320);
					auto rotation_y = glm::rotate(glm::mat4(), (i * 18.f) * (float)DEG_TO_RAD, glm::vec3(0, 1, 0));
					location = glm::vec4(location, 0) * rotation_y;

					auto noise_value = ofNoise(noise_param, cos(i * 18.f * DEG_TO_RAD), sin(i * 18.f * DEG_TO_RAD), ofGetFrameNum() * 0.06);
					float param = noise_value;
					location += glm::vec3(0, ofMap(noise_value, 0, 1, -100, 100), 0);

					if (location.y > 0) {

						ofVertex(location - glm::vec3(0, 100, 0));
					}
				}
			}
			ofEndShape();

			ofNoFill();
			ofSetColor(255, 0, 0);
			ofBeginShape();
			for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

				if (outline_index != 0) { ofNextContour(true); }

				auto vertices = outline[outline_index].getResampledByCount(sample_count).getVertices();
				for (auto& vertex : vertices) {

					auto location = vertex - glm::vec3(this->font_size * 0.5, this->font_size * -0.5, 320);
					auto rotation_y = glm::rotate(glm::mat4(), (i * 18.f) * (float)DEG_TO_RAD, glm::vec3(0, 1, 0));
					location = glm::vec4(location, 0) * rotation_y;

					auto noise_value = ofNoise(noise_param, cos(i * 18.f * DEG_TO_RAD), sin(i * 18.f * DEG_TO_RAD), ofGetFrameNum() * 0.06);
					float param = noise_value;
					location += glm::vec3(0, ofMap(noise_value, 0, 1, -100, 100), 0);

					if (location.y > 0) {

						ofVertex(location - glm::vec3(0, 100, 0));
					}
				}
			}
			ofEndShape();
		}

		for (int i = 0; i < word.size(); i++) {

			ofPath chara_path = this->font.getCharacterAsPoints(word[i], true, false);
			vector<ofPolyline> outline = chara_path.getOutline();

			ofFill();
			ofSetColor(0);
			ofBeginShape();
			for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

				if (outline_index != 0) { ofNextContour(true); }

				auto vertices = outline[outline_index].getResampledByCount(sample_count).getVertices();
				for (auto& vertex : vertices) {

					auto location = vertex - glm::vec3(this->font_size * 0.5, this->font_size * -0.5, 320);
					auto rotation_y = glm::rotate(glm::mat4(), (i * 18.f) * (float)DEG_TO_RAD, glm::vec3(0, 1, 0));
					location = glm::vec4(location, 0) * rotation_y;

					auto noise_value = ofNoise(noise_param, cos(i * 18.f * DEG_TO_RAD), sin(i * 18.f * DEG_TO_RAD), ofGetFrameNum() * 0.06);
					float param = noise_value;
					location += glm::vec3(0, ofMap(noise_value, 0, 1, -100, 100), 0);

					if (location.y < 0) {

						ofVertex(location + glm::vec3(0, 100, 0));
					}
				}
			}
			ofEndShape();

			ofNoFill();
			ofSetColor(255, 0, 0);
			ofBeginShape();
			for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

				if (outline_index != 0) { ofNextContour(true); }

				auto vertices = outline[outline_index].getResampledByCount(sample_count).getVertices();
				for (auto& vertex : vertices) {

					auto location = vertex - glm::vec3(this->font_size * 0.5, this->font_size * -0.5, 320);
					auto rotation_y = glm::rotate(glm::mat4(), (i * 18.f) * (float)DEG_TO_RAD, glm::vec3(0, 1, 0));
					location = glm::vec4(location, 0) * rotation_y;

					auto noise_value = ofNoise(noise_param, cos(i * 18.f * DEG_TO_RAD), sin(i * 18.f * DEG_TO_RAD), ofGetFrameNum() * 0.06);
					float param = noise_value;
					location += glm::vec3(0, ofMap(noise_value, 0, 1, -100, 100), 0);

					if (location.y < 0) {

						ofVertex(location + glm::vec3(0, 100, 0));
					}
				}
			}
			ofEndShape();
		}

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}