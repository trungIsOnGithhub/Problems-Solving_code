class PlanController < ApplicationController
    before_action :authenticate_user!
    before_action :set_plan, only: [:show, :edit, :update, :destroy]

    # GET /plan
    # GET /plan.json
    def index
        @plans =  current_user.plans
    end
end